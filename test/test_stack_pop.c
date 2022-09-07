/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:32:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 21:33:40 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_pop);

static t_stack *stack;
static t_node *pop;

TEST_SETUP(stack_pop) 
{
	stack = stack_create();
}

TEST_TEAR_DOWN(stack_pop) 
{
	stack_destroy(&stack);
}

TEST(stack_pop, PopWithNullPointer)
{
	TEST_ASSERT_NULL(stack_pop(NULL));
}

TEST(stack_pop, OneItem)
{
	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NULL(stack->items);

	stack_push(stack, 21);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_EQUAL_INT(21, stack->items->value);

	pop = stack_pop(stack);
	TEST_ASSERT_NOT_NULL(pop);
	TEST_ASSERT_EQUAL_INT(21, pop->value);
	TEST_ASSERT_NULL(stack->items);

	free(pop);
}

TEST(stack_pop, MultiItems)
{
	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NULL(stack->items);

	stack_push(stack, 21);
	stack_push(stack, 42);
	TEST_ASSERT_EQUAL_INT(42, stack->items->value);
	TEST_ASSERT_EQUAL_INT(21, stack->items->next->value);

	pop = stack_pop(stack);
	TEST_ASSERT_NOT_NULL(pop);
	TEST_ASSERT_EQUAL_INT(42, pop->value);
	TEST_ASSERT_NULL(pop->next);
	TEST_ASSERT_NOT_NULL(stack->items);
	TEST_ASSERT_EQUAL_INT(21, stack->items->value);

	free(pop);
}

TEST_GROUP_RUNNER(stack_pop)
{
	RUN_TEST_CASE(stack_pop, PopWithNullPointer);
	RUN_TEST_CASE(stack_pop, OneItem);
	RUN_TEST_CASE(stack_pop, MultiItems);
}
