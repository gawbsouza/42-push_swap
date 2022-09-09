/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:57:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 09:52:15 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pa);

static t_pswap *ps;

TEST_SETUP(pa)
{
	ps = pswap_create();
	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(pa)
{
	pswap_destroy(&ps);
}

TEST(pa, EmptyAAndEmptyB)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	pa(ps);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
}

TEST(pa, EmptyAAndOneItemInB)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	stack_push(ps->b, 21);
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);

	pa(ps);

	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
}

TEST(pa, OneItemInAAndOneItemInB)
{
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	
	stack_push(ps->a, 42);
	stack_push(ps->b, 21);
	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);

	pa(ps);

	TEST_ASSERT_EQUAL_INT(2, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_EQUAL_INT(21, stack_pop(ps->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(ps->a));
}

TEST_GROUP_RUNNER(pa)
{
	RUN_TEST_CASE(pa, EmptyAAndEmptyB);
	RUN_TEST_CASE(pa, EmptyAAndOneItemInB);
	RUN_TEST_CASE(pa, OneItemInAAndOneItemInB);
}
