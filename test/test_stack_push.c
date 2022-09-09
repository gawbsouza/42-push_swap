/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:00:25 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 10:42:33 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_push);

static t_stack *stack;

TEST_SETUP(stack_push)
{
    stack = stack_create();
    TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_push)
{
	stack_destroy(&stack);
}

TEST(stack_push, PushOneItem)
{
    stack_push(stack, 21);
    TEST_ASSERT_NOT_NULL(stack->items);
    TEST_ASSERT_EQUAL_INT(1, stack->size);
    TEST_ASSERT_EQUAL_INT(21, stack->items->value);
    TEST_ASSERT_NULL(stack->last->next);
	TEST_ASSERT_EQUAL_PTR(stack->last, stack->items);
    TEST_ASSERT_NULL(stack->last->next);
}

TEST(stack_push, PushTwoItems)
{
    stack_push(stack, 21);
	stack_push(stack, 42);
    TEST_ASSERT_EQUAL_INT(2, stack->size);
    TEST_ASSERT_EQUAL_INT(42, stack->items->value);
    TEST_ASSERT_EQUAL_INT(21, stack->items->next->value);
	TEST_ASSERT_EQUAL_PTR(stack->last, stack->items->next);
    TEST_ASSERT_NULL(stack->last->next);
}

TEST(stack_push, PushMultiItems)
{
    stack_push(stack, 21);
	stack_push(stack, 42);
	stack_push(stack, 64);
    TEST_ASSERT_EQUAL_INT(3, stack->size);
    TEST_ASSERT_EQUAL_INT(64, stack->items->value);
    TEST_ASSERT_EQUAL_INT(42, stack->items->next->value);
    TEST_ASSERT_EQUAL_INT(21, stack->items->next->next->value);
	TEST_ASSERT_EQUAL_PTR(stack->last, stack->items->next->next);
    TEST_ASSERT_NULL(stack->last->next);
}

TEST_GROUP_RUNNER(stack_push)
{
	RUN_TEST_CASE(stack_push, PushOneItem);
	RUN_TEST_CASE(stack_push, PushTwoItems);
	RUN_TEST_CASE(stack_push, PushMultiItems);
}
