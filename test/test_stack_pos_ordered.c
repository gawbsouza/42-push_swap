/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_pos_ordered.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:16:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/10 17:45:39 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_pos_ordered);

static t_stack *stack;

TEST_SETUP(stack_pos_ordered)
{
	stack = stack_create();

	TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_pos_ordered)
{
	stack_destroy(&stack);
}

TEST(stack_pos_ordered, NullStackPointer)
{
	TEST_ASSERT_EQUAL_INT(-1, stack_pos_ordered(NULL, 1));
}

TEST(stack_pos_ordered, WithEmptyStack)
{
	TEST_ASSERT_EQUAL_INT(-1, stack_pos_ordered(stack, 1));
}

TEST(stack_pos_ordered, WithOneItemInStack)
{
	stack_push(stack, 42);

	TEST_ASSERT_EQUAL_INT(1, stack_pos_ordered(stack, 1));
}

TEST(stack_pos_ordered, WithInvalidPositionNumber)
{
	stack_push(stack, 42);

	TEST_ASSERT_EQUAL_INT(-1, stack_pos_ordered(stack, 0));
	TEST_ASSERT_EQUAL_INT(-1, stack_pos_ordered(stack, 2));
	TEST_ASSERT_EQUAL_INT(-1, stack_pos_ordered(stack, 50));
}

TEST(stack_pos_ordered, WithTwoItemsOrderedInStack)
{
	stack_push(stack, 42);
	stack_push(stack, 21);

	TEST_ASSERT_EQUAL_INT(1, stack_pos_ordered(stack, 1));
	TEST_ASSERT_EQUAL_INT(1, stack_pos_ordered(stack, 2));
}

TEST(stack_pos_ordered, WithTwoItemsUnorderedInStack)
{
	stack_push(stack, 21);
	stack_push(stack, 42);

	TEST_ASSERT_EQUAL_INT(0, stack_pos_ordered(stack, 1));
	TEST_ASSERT_EQUAL_INT(1, stack_pos_ordered(stack, 2));
}

TEST(stack_pos_ordered, WithMultiItemsInStack)
{
	stack_push(stack, 2);
	stack_push(stack, 4);
	stack_push(stack, 1);
	stack_push(stack, 3);
	stack_push(stack, 5);

	// 5 3 1 4 2
	TEST_ASSERT_EQUAL_INT(0, stack_pos_ordered(stack, 1));
	TEST_ASSERT_EQUAL_INT(0, stack_pos_ordered(stack, 2));
	TEST_ASSERT_EQUAL_INT(1, stack_pos_ordered(stack, 3));
	TEST_ASSERT_EQUAL_INT(0, stack_pos_ordered(stack, 4));
	TEST_ASSERT_EQUAL_INT(1, stack_pos_ordered(stack, 5));
}


TEST_GROUP_RUNNER(stack_pos_ordered)
{
	RUN_TEST_CASE(stack_pos_ordered, NullStackPointer);
	RUN_TEST_CASE(stack_pos_ordered, WithEmptyStack);
	RUN_TEST_CASE(stack_pos_ordered, WithOneItemInStack);
	RUN_TEST_CASE(stack_pos_ordered, WithInvalidPositionNumber);
	RUN_TEST_CASE(stack_pos_ordered, WithTwoItemsOrderedInStack);
	RUN_TEST_CASE(stack_pos_ordered, WithTwoItemsUnorderedInStack);
	RUN_TEST_CASE(stack_pos_ordered, WithMultiItemsInStack);
}
