/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_up_cmds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:17:28 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 17:24:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(rotate_up_cmds);

TEST_SETUP(rotate_up_cmds)
{
}

TEST_TEAR_DOWN(rotate_up_cmds)
{
}

TEST(rotate_up_cmds, FastTest)
{
	t_pswap *ps = pswap_create(stack_create(), stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_NOT_NULL(ps->b);

	stack_push(ps->a, 21);
	stack_push(ps->a, 42);
	stack_push(ps->b, 51);
	stack_push(ps->b, 102);

	TEST_ASSERT_EQUAL_INT(42, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->value);
	TEST_ASSERT_EQUAL_INT(102, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(51, ps->b->items->next->value);
	
	ra(ps);
	rb(ps);

	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(42, ps->a->items->next->value);
	TEST_ASSERT_EQUAL_INT(51, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(102, ps->b->items->next->value);

	rr(ps);

	TEST_ASSERT_EQUAL_INT(42, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->value);
	TEST_ASSERT_EQUAL_INT(102, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(51, ps->b->items->next->value);
	
	pswap_destroy(&ps);
}

TEST_GROUP_RUNNER(rotate_up_cmds)
{
	RUN_TEST_CASE(rotate_up_cmds, FastTest);
}
