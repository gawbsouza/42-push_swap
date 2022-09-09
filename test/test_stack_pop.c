/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:32:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 09:31:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_pop);

static t_stack *stack;
static t_node *last;

TEST_SETUP(stack_pop) 
{
	stack = stack_create();
	TEST_ASSERT_NOT_NULL(stack);
}

TEST_TEAR_DOWN(stack_pop) 
{
	stack_destroy(&stack);
}

TEST(stack_pop, OneItem)
{
	stack_push(stack, 21);
	TEST_ASSERT_EQUAL_INT(1, stack->size);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_NOT_NULL(stack->last);

	TEST_ASSERT_EQUAL_INT(21, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(0, stack->size);

	TEST_ASSERT_NULL(stack->items);
	TEST_ASSERT_NULL(stack->last);
}

TEST(stack_pop, TwoItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	TEST_ASSERT_EQUAL_INT(2, stack->size);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_NOT_NULL(stack->last);

	last = stack->last;

	TEST_ASSERT_EQUAL_INT(42, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(1, stack->size);
	TEST_ASSERT_EQUAL_PTR(last, stack->last);

	TEST_ASSERT_EQUAL_INT(21, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(0, stack->size);
	
	TEST_ASSERT_NULL(stack->items);
	TEST_ASSERT_NULL(stack->last);
}

TEST(stack_pop, MultiItems)
{
	stack_push(stack, 21);
	stack_push(stack, 42);
	stack_push(stack, 64);
	TEST_ASSERT_EQUAL_INT(3, stack->size);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_NOT_NULL(stack->last);
	
	last = stack->last;

	TEST_ASSERT_EQUAL_INT(64, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(2, stack->size);
	TEST_ASSERT_EQUAL_PTR(last, stack->last);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(1, stack->size);
	TEST_ASSERT_EQUAL_PTR(last, stack->last);

	TEST_ASSERT_EQUAL_INT(21, stack_pop(stack));
	TEST_ASSERT_EQUAL_INT(0, stack->size);

	TEST_ASSERT_NULL(stack->items);
	TEST_ASSERT_NULL(stack->last);
}

TEST_GROUP_RUNNER(stack_pop)
{
	RUN_TEST_CASE(stack_pop, OneItem);
	RUN_TEST_CASE(stack_pop, TwoItems);
	RUN_TEST_CASE(stack_pop, MultiItems);
}
