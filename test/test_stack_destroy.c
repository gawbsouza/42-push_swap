/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:20:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 10:23:08 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_destroy);

static t_stack *stack;

TEST_SETUP(stack_destroy)
{
	stack = stack_create();
	TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_destroy)
{
	stack_destroy(&stack);
	TEST_ASSERT_NULL(stack);
}

TEST(stack_destroy, StackWithNoItem)
{
	TEST_ASSERT_EQUAL_INT(0, stack->size);
}

TEST(stack_destroy, StackWithOneItem)
{
	stack_push(stack, 21);
	TEST_ASSERT_EQUAL_INT(1, stack->size);
}

TEST(stack_destroy, StackWithTwoItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	TEST_ASSERT_EQUAL_INT(2, stack->size);
}

TEST(stack_destroy, StackWithMultiItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	stack_push(stack, 64);
	TEST_ASSERT_EQUAL_INT(3, stack->size);
}

TEST_GROUP_RUNNER(stack_destroy)
{
	RUN_TEST_CASE(stack_destroy, StackWithNoItem);
	RUN_TEST_CASE(stack_destroy, StackWithOneItem);
	RUN_TEST_CASE(stack_destroy, StackWithTwoItems);
	RUN_TEST_CASE(stack_destroy, StackWithMultiItems);
}
