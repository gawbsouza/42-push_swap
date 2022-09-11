/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_is_ordered.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 08:26:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 09:08:25 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_is_ordered);

static t_stack *stack;

TEST_SETUP(stack_is_ordered)
{
	stack = stack_create();

	TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_is_ordered)
{
	stack_destroy(&stack);
}

TEST(stack_is_ordered, NullPointerStack)
{
	TEST_ASSERT_FALSE(stack_is_ordered(NULL));
}

TEST(stack_is_ordered, EmptyStack)
{
	TEST_ASSERT_TRUE(stack_is_ordered(stack));
}

TEST(stack_is_ordered, WithOneItem)
{
	stack_push(stack, 42);

	TEST_ASSERT_TRUE(stack_is_ordered(stack));
}

TEST(stack_is_ordered, WithTwoItemsOrdered)
{
	stack_push(stack, 42);
	stack_push(stack, 21);

	// 21 42
	TEST_ASSERT_TRUE(stack_is_ordered(stack));
}

TEST(stack_is_ordered, WithTwoItemsUnordered)
{
	stack_push(stack, 21);
	stack_push(stack, 42);

	// 42 21
	TEST_ASSERT_FALSE(stack_is_ordered(stack));
}

TEST(stack_is_ordered, WithThreeItemsOrdered)
{
	stack_push(stack, 64);
	stack_push(stack, 42);
	stack_push(stack, 21);

	// 21 42 64
	TEST_ASSERT_TRUE(stack_is_ordered(stack));
}

TEST(stack_is_ordered, WithThreeItemsUnordered)
{
	stack_push(stack, 42);
	stack_push(stack, 64);
	stack_push(stack, 21);

	// 21 64 42
	TEST_ASSERT_FALSE(stack_is_ordered(stack));
}


TEST_GROUP_RUNNER(stack_is_ordered)
{
	RUN_TEST_CASE(stack_is_ordered, NullPointerStack);
	RUN_TEST_CASE(stack_is_ordered, EmptyStack);
	RUN_TEST_CASE(stack_is_ordered, WithOneItem);
	RUN_TEST_CASE(stack_is_ordered, WithTwoItemsOrdered);
	RUN_TEST_CASE(stack_is_ordered, WithTwoItemsUnordered);
	RUN_TEST_CASE(stack_is_ordered, WithThreeItemsOrdered);
	RUN_TEST_CASE(stack_is_ordered, WithThreeItemsUnordered);
}
