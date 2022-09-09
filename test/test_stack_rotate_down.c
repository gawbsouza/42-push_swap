/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_rotate_down.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:35:28 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:11:12 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_rotate_down);

static t_stack *stack;

TEST_SETUP(stack_rotate_down)
{
	stack = stack_create();
	TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_rotate_down)
{
	stack_destroy(&stack);
}

TEST(stack_rotate_down, EmptyStack)
{
	TEST_ASSERT_EQUAL_INT(0, stack->size);

	stack_rotate_down(stack);

	TEST_ASSERT_EQUAL_INT(0, stack->size);
}

TEST(stack_rotate_down, StackWithOneItem)
{
	stack_push(stack, 21);
	TEST_ASSERT_EQUAL_INT(1, stack->size);

	stack_rotate_down(stack);

	TEST_ASSERT_EQUAL_INT(1, stack->size);
	TEST_ASSERT_NULL(stack->last->next);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(stack));
}

TEST(stack_rotate_down, StackWithTwoItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	TEST_ASSERT_EQUAL_INT(2, stack->size);

	stack_rotate_down(stack);

	TEST_ASSERT_EQUAL_INT(2, stack->size);
	TEST_ASSERT_EQUAL_PTR(stack->last, stack->items->next);
	TEST_ASSERT_NULL(stack->last->next);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(stack));
}

TEST(stack_rotate_down, StackWithMultiItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	stack_push(stack, 64);
	TEST_ASSERT_EQUAL_INT(3, stack->size);

	stack_rotate_down(stack);

	TEST_ASSERT_EQUAL_INT(3, stack->size);
	TEST_ASSERT_EQUAL_PTR(stack->last, stack->items->next->next);
	TEST_ASSERT_NULL(stack->last->next);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(stack));
}

TEST_GROUP_RUNNER(stack_rotate_down)
{
	RUN_TEST_CASE(stack_rotate_down, EmptyStack);
	RUN_TEST_CASE(stack_rotate_down, StackWithOneItem);
	RUN_TEST_CASE(stack_rotate_down, StackWithTwoItems);
	RUN_TEST_CASE(stack_rotate_down, StackWithMultiItems);
}
