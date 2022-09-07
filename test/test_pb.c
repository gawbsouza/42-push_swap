/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:57:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 16:56:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pb);

static t_pswap *ps;

TEST_SETUP(pb)
{
}

TEST_TEAR_DOWN(pb)
{
	pswap_destroy(&ps);
}

TEST(pb, WithNullStacks)
{
	ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	pb(ps);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);
}

TEST(pb, WithOneItemInAAndNullInB)
{
	ps = pswap_create(stack_create(), NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	stack_push(ps->a, 21);

	pb(ps);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->b->items);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->value);
	TEST_ASSERT_NULL(ps->a->items);
}

TEST(pb, WithOneItemInAAndOneItemInB)
{
	ps = pswap_create(stack_create(), stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_NOT_NULL(ps->b);

	stack_push(ps->a, 42);
	stack_push(ps->b, 21);

	pb(ps);

	TEST_ASSERT_EQUAL_INT(42, ps->b->items->value);
	TEST_ASSERT_EQUAL_INT(21, ps->b->items->next->value);
	TEST_ASSERT_NULL(ps->a->items);
}

TEST_GROUP_RUNNER(pb)
{
	RUN_TEST_CASE(pb, WithNullStacks);
	RUN_TEST_CASE(pb, WithOneItemInAAndNullInB);
	RUN_TEST_CASE(pb, WithOneItemInAAndOneItemInB);
}
