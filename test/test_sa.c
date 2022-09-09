/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:49:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 10:31:54 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(sa);

static t_pswap *ps;

TEST_SETUP(sa)
{
	ps = pswap_create();
	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(sa)
{
	pswap_destroy(&ps);
}

TEST(sa, WithEmptyStacks)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);

	sa(ps);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
}

TEST(sa, WithOneItemInStackA)
{
	stack_push(ps->a, 21);
	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	sa(ps);
	
	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
}

TEST(sa, WithTwoItemsInStack)
{
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	TEST_ASSERT_EQUAL_INT(2, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	sa(ps);
	
	TEST_ASSERT_EQUAL_INT(2, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));
}

TEST(sa, WithMultiItemsInStack)
{
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	stack_push(ps->a, 64);
	TEST_ASSERT_EQUAL_INT(3, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	sa(ps);
	
	TEST_ASSERT_EQUAL_INT(3, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
}

TEST_GROUP_RUNNER(sa)
{
	RUN_TEST_CASE(sa, WithEmptyStacks);
	RUN_TEST_CASE(sa, WithOneItemInStackA);
	RUN_TEST_CASE(sa, WithTwoItemsInStack);
	RUN_TEST_CASE(sa, WithMultiItemsInStack);
}
