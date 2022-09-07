/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:49:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 13:22:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(sb);

static t_pswap *ps;

TEST_SETUP(sb)
{
}

TEST_TEAR_DOWN(sb)
{
	pswap_destroy(&ps);
}

TEST(sb, WithNullStacks)
{
	ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	sb(ps);

	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);
}

TEST(sb, WithOneItemInStack)
{
	ps = pswap_create(NULL, stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->b);
	
	stack_push(ps->b, 21);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->value);
	TEST_ASSERT_NULL(ps->a);

	sb(ps);
	TEST_ASSERT_NOT_NULL(ps->b);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->value);
	TEST_ASSERT_NULL(ps->a);
}

TEST(sb, WithTwoItemsInStack)
{
	ps = pswap_create(NULL, stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->b);
	
	stack_push(ps->b, 21);
	stack_push(ps->b, 42);
	TEST_ASSERT_EQUAL_INT(42, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->next->value);
	TEST_ASSERT_NULL(ps->a);

	sb(ps);
	TEST_ASSERT_NOT_NULL(ps->b);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(42, ps->b->items->next->value);
	TEST_ASSERT_NULL(ps->a);
}

TEST(sb, WithMultiItemsInStack)
{
	ps = pswap_create(NULL, stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->b);
	
	stack_push(ps->b, 21);
	stack_push(ps->b, 42);
	stack_push(ps->b, 64);
	TEST_ASSERT_EQUAL_INT(64, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(42, ps->b->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->next->next->value);
	TEST_ASSERT_NULL(ps->a);

	sb(ps);
	TEST_ASSERT_NOT_NULL(ps->b);
	TEST_ASSERT_EQUAL_INT(42, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(64, ps->b->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->next->next->value);
	TEST_ASSERT_NULL(ps->a);
}

TEST_GROUP_RUNNER(sb)
{
	RUN_TEST_CASE(sb, WithNullStacks);
	RUN_TEST_CASE(sb, WithOneItemInStack);
	RUN_TEST_CASE(sb, WithTwoItemsInStack);
	RUN_TEST_CASE(sb, WithMultiItemsInStack);
}
