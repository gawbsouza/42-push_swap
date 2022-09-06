/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:20:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 19:47:54 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_destroy);

static t_stack *stack;

static t_node *node_create(unsigned int value)
{
	t_node *node;
	
	node = (t_node *) malloc(sizeof(t_node));
	if (node)
	{
		node->value = value;
		node->next = NULL;
	}
	return (node);
}


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


TEST(stack_destroy, StackWithOneNode)
{
	t_node *node = node_create(21);
	
	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_INT(21, node->value);

	stack->items = node;
}

TEST(stack_destroy, StackWithMultiNode)
{
	t_node *node1 = node_create(21);
	t_node *node2 = node_create(42);
	
	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NOT_NULL(node1);
	TEST_ASSERT_NOT_NULL(node2);

	stack->items = node1;
	stack->items->next = node2;
}

TEST_GROUP_RUNNER(stack_destroy)
{
	RUN_TEST_CASE(stack_destroy, StackWithOneNode);
	RUN_TEST_CASE(stack_destroy, StackWithMultiNode);
}
