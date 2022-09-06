/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:20:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 11:29:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_create);

TEST_SETUP(stack_create)
{
}

TEST_TEAR_DOWN(stack_create)
{
}

TEST(stack_create, Create)
{
	t_stack	*stack = stack_create();

	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NULL(stack->items);

	free(stack);
}

TEST_GROUP_RUNNER(stack_create)
{
	RUN_TEST_CASE(stack_create, Create);
}
