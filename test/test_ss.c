/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:49:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 13:51:08 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(ss);

static t_pswap *ps;

TEST_SETUP(ss)
{
	ps = pswap_create(stack_create(), stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_NOT_NULL(ps->b);
}

TEST_TEAR_DOWN(ss)
{
	pswap_destroy(&ps);
}

TEST(ss, WithNullStacks)
{
	t_pswap *ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	ss(ps);
	
	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	pswap_destroy(&ps);
}

TEST(ss, WithOneItem)
{
	stack_push(ps->a, 21);
	stack_push(ps->b, 51);
	
	ss(ps);
	
	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(51, ps->b->items->value);
}

TEST(ss, WithTwoItems)
{
	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	
	stack_push(ps->b, 51);
	stack_push(ps->b, 102);
	
	ss(ps);
	
	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->next->value);

	TEST_ASSERT_EQUAL_INT(51, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(102, ps->b->items->next->value);
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
	
	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(64, ps->a->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->next->value);

	TEST_ASSERT_EQUAL_INT(102, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(154, ps->b->items->next->value);
	TEST_ASSERT_EQUAL_INT(51, ps->b->items->next->next->value);
}

TEST_GROUP_RUNNER(ss)
{
	RUN_TEST_CASE(ss, WithNullStacks);
	RUN_TEST_CASE(ss, WithOneItem);
	RUN_TEST_CASE(ss, WithTwoItems);
	RUN_TEST_CASE(ss, WithMultiItems);
}
