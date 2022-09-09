/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:49:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:13:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(ss);

static t_pswap *ps;

TEST_SETUP(ss)
{
	ps = pswap_create();

	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(ss)
{
	pswap_destroy(&ps);
}

TEST(ss, WithEmptyStacks)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);

	ss(ps);
	
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	pswap_destroy(&ps);
}

TEST(ss, WithOneItem)
{
	stack_push(ps->a, 21);
	stack_push(ps->b, 51);
	
	ss(ps);
	
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(51, stack_pop(ps->b));
}

TEST(ss, WithTwoItems)
{
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	
	stack_push(ps->b, 51);
	stack_push(ps->b, 102);
	
	ss(ps);
	
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));

	TEST_ASSERT_EQUAL_INT(51, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(102, stack_pop(ps->b));
}

TEST(ss, WithMultiItems)
{
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	stack_push(ps->a, 64);
	
	stack_push(ps->b, 51);
	stack_push(ps->b, 102);
	stack_push(ps->b, 154);
	
	ss(ps);
	
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));

	TEST_ASSERT_EQUAL_INT(102, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(51, stack_pop(ps->b));
}

TEST_GROUP_RUNNER(ss)
{
	RUN_TEST_CASE(ss, WithEmptyStacks);
	RUN_TEST_CASE(ss, WithOneItem);
	RUN_TEST_CASE(ss, WithTwoItems);
	RUN_TEST_CASE(ss, WithMultiItems);
}
