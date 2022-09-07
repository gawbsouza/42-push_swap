/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:57:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 16:24:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pa);

static t_pswap *ps;

TEST_SETUP(pa)
{
}

TEST_TEAR_DOWN(pa)
{
	pswap_destroy(&ps);
}

TEST(pa, WithNullStacks)
{
	ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);

	pa(ps);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);
}

TEST(pa, WithOneItemInBAndNullInA)
{
	ps = pswap_create(NULL, stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NOT_NULL(ps->b);

	stack_push(ps->b, 21);

	pa(ps);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a->items);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->value);
	TEST_ASSERT_NULL(ps->b->items);
}

TEST(pa, WithOneItemInBAndOneItemInA)
{
	ps = pswap_create(stack_create(), stack_create());

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_NOT_NULL(ps->b);

	stack_push(ps->a, 21);
	stack_push(ps->b, 42);

	pa(ps);

	TEST_ASSERT_EQUAL_INT(42, ps->a->items->value);
	TEST_ASSERT_EQUAL_INT(21, ps->a->items->next->value);
	TEST_ASSERT_NULL(ps->b->items);
}

TEST_GROUP_RUNNER(pa)
{
	RUN_TEST_CASE(pa, WithNullStacks);
	RUN_TEST_CASE(pa, WithOneItemInBAndNullInA);
	RUN_TEST_CASE(pa, WithOneItemInBAndOneItemInA);
}
