/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pswap_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:30:26 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 11:56:25 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pswap_create);

static t_pswap *ps;
static t_stack *a;
static t_stack *b;

TEST_SETUP(pswap_create)
{
	ps = NULL;
	a = stack_create();
	b = stack_create();

	TEST_ASSERT_NOT_NULL(a);
	TEST_ASSERT_NOT_NULL(b);
}

TEST_TEAR_DOWN(pswap_create)
{
	stack_destroy(&a);
	stack_destroy(&b);
	free(ps);
}

TEST(pswap_create, CreateWithNullStacks)
{
	ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NULL(ps->a);
	TEST_ASSERT_NULL(ps->b);
}

TEST(pswap_create, CreateWithStackA)
{
	ps = pswap_create(a, NULL);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_EQUAL_PTR(a, ps->a);
	TEST_ASSERT_NULL(ps->b);
}

TEST(pswap_create, CreateWithStackB)
{
	ps = pswap_create(NULL, b);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_EQUAL_PTR(b, ps->b);
	TEST_ASSERT_NULL(ps->a);
}

TEST(pswap_create, CreateWithStacksAB)
{
	ps = pswap_create(a, b);

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_EQUAL_PTR(a, ps->a);
	TEST_ASSERT_EQUAL_PTR(b, ps->b);
}

TEST_GROUP_RUNNER(pswap_create)
{
	RUN_TEST_CASE(pswap_create, CreateWithNullStacks);
	RUN_TEST_CASE(pswap_create, CreateWithStackA);
	RUN_TEST_CASE(pswap_create, CreateWithStackB);
	RUN_TEST_CASE(pswap_create, CreateWithStacksAB);
}
