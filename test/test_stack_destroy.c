/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:20:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 14:09:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(stack_destroy);

TEST_SETUP(stack_destroy)
{
}

TEST_TEAR_DOWN(stack_destroy)
{
}

TEST(stack_destroy, Destroy)
{
	t_stack	*stack = stack_create();

	TEST_ASSERT_NOT_NULL(stack);

	stack_destroy(&stack);
	TEST_ASSERT_NULL(stack);
}

TEST_GROUP_RUNNER(stack_destroy)
{
	RUN_TEST_CASE(stack_destroy, Destroy);
}
