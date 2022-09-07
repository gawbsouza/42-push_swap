/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:49:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 13:24:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(sa);

static t_pswap *ps;

TEST_SETUP(sa)
{
}

TEST_TEAR_DOWN(sa)
{
	pswap_destroy(&ps);
}

TEST(sa, WithNullStacks)
{
	ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	sa(ps);

	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);
}

TEST(sa, WithOneItemInStack)
{
	ps = pswap_create(stack_create(), NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	
	stack_push(ps->a, 21);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_NULL(ps->b);

	sa(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_NULL(ps->b);
}

TEST(sa, WithTwoItemsInStack)
{
	ps = pswap_create(stack_create(), NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->value);
	TEST_ASSERT_NULL(ps->b);

	sa(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->next->value);
	TEST_ASSERT_NULL(ps->b);
}

TEST(sa, WithMultiItemsInStack)
{
	ps = pswap_create(stack_create(), NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	stack_push(ps->a, 64);
	TEST_ASSERT_EQUAL_INT(64, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->next->value);
	TEST_ASSERT_NULL(ps->b);

	sa(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(64, ps->a->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->next->value);
	TEST_ASSERT_NULL(ps->b);
}

TEST_GROUP_RUNNER(sa)
{
	RUN_TEST_CASE(sa, WithNullStacks);
	RUN_TEST_CASE(sa, WithOneItemInStack);
	RUN_TEST_CASE(sa, WithTwoItemsInStack);
	RUN_TEST_CASE(sa, WithMultiItemsInStack);
}
