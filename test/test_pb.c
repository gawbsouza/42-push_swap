/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:57:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:15:34 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pb);

static t_pswap *ps;

TEST_SETUP(pb)
{
	ps = pswap_create();
	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(pb)
{
	pswap_destroy(&ps);
}

TEST(pb, EmptyAAndEmptyB)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	pb(ps);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
}

TEST(pb, EmptyAAndOneItemInB)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	stack_push(ps->a, 21);
	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);

	pb(ps);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->b));
}

TEST(pb, OneItemInAAndOneItemInB)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	stack_push(ps->a, 42);
	stack_push(ps->b, 21);
	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);

	pb(ps);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(2, ps->b->size);
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->b));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->b));
}

TEST_GROUP_RUNNER(pb)
{
	RUN_TEST_CASE(pb, EmptyAAndEmptyB);
	RUN_TEST_CASE(pb, EmptyAAndOneItemInB);
	RUN_TEST_CASE(pb, OneItemInAAndOneItemInB);
}
