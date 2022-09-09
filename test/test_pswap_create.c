/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pswap_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:30:26 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:12:23 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pswap_create);

TEST_SETUP(pswap_create)
{
}

TEST_TEAR_DOWN(pswap_create)
{
}

TEST(pswap_create, Create)
{
	t_pswap *ps = pswap_create();

	TEST_ASSERT_NOT_NULL(ps);
	TEST_ASSERT_NOT_NULL(ps->a);
	TEST_ASSERT_NOT_NULL(ps->b);
	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);

	stack_destroy(&ps->a);
	stack_destroy(&ps->b);
	free(ps);
}

TEST_GROUP_RUNNER(pswap_create)
{
	RUN_TEST_CASE(pswap_create, Create);
}
