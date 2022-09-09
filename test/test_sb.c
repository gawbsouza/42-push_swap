/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:49:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 10:31:54 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(sb);

static t_pswap *ps;

TEST_SETUP(sb)
{
	ps = pswap_create();
	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(sb)
{
	pswap_destroy(&ps);
}

TEST(sb, WithEmptyStacks)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);

	sb(ps);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
}

TEST(sb, WithOneItemInStackA)
{
	stack_push(ps->b, 21);
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);
	
	sb(ps);
	
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->b));
}

TEST(sb, WithTwoItemsInStack)
{
	stack_push(ps->b, 21);
	stack_push(ps->b, 42);
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(2, ps->b->size);
	
	sb(ps);
	
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(2, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->b));
}

TEST(sb, WithMultiItemsInStack)
{
	stack_push(ps->b, 21);
	stack_push(ps->b, 42);
	stack_push(ps->b, 64);
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(3, ps->b->size);
	
	sb(ps);
	
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(3, ps->b->size);
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->b));
}

TEST_GROUP_RUNNER(sb)
{
	RUN_TEST_CASE(sb, WithEmptyStacks);
	RUN_TEST_CASE(sb, WithOneItemInStackA);
	RUN_TEST_CASE(sb, WithTwoItemsInStack);
	RUN_TEST_CASE(sb, WithMultiItemsInStack);
}
