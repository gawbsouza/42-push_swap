/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_down_cmds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:17:28 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:17:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(rotate_down_cmds);

static t_pswap *ps;

TEST_SETUP(rotate_down_cmds)
{
	ps = pswap_create();

	TEST_ASSERT_NOT_NULL(ps);

	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	stack_push(ps->a, 64);

	stack_push(ps->b, 51);
	stack_push(ps->b, 102);
	stack_push(ps->b, 154);
}

TEST_TEAR_DOWN(rotate_down_cmds)
{
	pswap_destroy(&ps);
}

TEST(rotate_down_cmds, rra)
{
	rra(ps);
	
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));
}

TEST(rotate_down_cmds, rrb)
{
	rrb(ps);

	TEST_ASSERT_EQUAL_INT(51, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(102, stack_pop(ps->b));
}

TEST(rotate_down_cmds, rrr)
{
	rrr(ps);

	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));

	TEST_ASSERT_EQUAL_INT(51, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(102, stack_pop(ps->b));
}

TEST_GROUP_RUNNER(rotate_down_cmds)
{
	RUN_TEST_CASE(rotate_down_cmds, rra);
	RUN_TEST_CASE(rotate_down_cmds, rrb);
	RUN_TEST_CASE(rotate_down_cmds, rrr);
}
