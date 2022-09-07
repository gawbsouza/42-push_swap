/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:37:52 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 22:13:25 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_swap);

static t_stack *stack;

TEST_SETUP(stack_swap)
{
	stack = stack_create();
	TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_swap)
{
	stack_destroy(&stack);
}

TEST(stack_swap, EmptyStack)
{
	TEST_ASSERT_NULL(stack->items);

	stack_swap(stack);
	TEST_ASSERT_NULL(stack->items);
}

TEST(stack_swap, OneItem)
{
	stack_push(stack, 21);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_EQUAL_INT(21, stack->items->value);

	stack_swap(stack);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_EQUAL_INT(21, stack->items->value);
}

TEST(stack_swap, TwoItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	TEST_ASSERT_EQUAL_INT(42, stack->items->value);
	TEST_ASSERT_EQUAL_INT(21, stack->items->next->value);

	stack_swap(stack);
	TEST_ASSERT_EQUAL_INT(21, stack->items->value);
	TEST_ASSERT_EQUAL_INT(42, stack->items->next->value);
}

TEST(stack_swap, MultiItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	stack_push(stack, 64);
	TEST_ASSERT_EQUAL_INT(64, stack->items->value);
	TEST_ASSERT_EQUAL_INT(42, stack->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, stack->items->next->next->value);

	stack_swap(stack);
	TEST_ASSERT_EQUAL_INT(42, stack->items->value);
	TEST_ASSERT_EQUAL_INT(64, stack->items->next->value);
	TEST_ASSERT_EQUAL_INT(21, stack->items->next->next->value);
}

TEST_GROUP_RUNNER(stack_swap)
{
	RUN_TEST_CASE(stack_swap, EmptyStack);
	RUN_TEST_CASE(stack_swap, OneItem);
	RUN_TEST_CASE(stack_swap, TwoItems);
	RUN_TEST_CASE(stack_swap, MultiItems);
}
