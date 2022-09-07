/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pswap_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:03:06 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 12:07:08 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pswap_destroy);

TEST_SETUP(pswap_destroy)
{
}

TEST_TEAR_DOWN(pswap_destroy)
{
}

TEST(pswap_destroy, Destroy)
{
	t_pswap *ps = pswap_create(NULL, NULL);

	TEST_ASSERT_NOT_NULL(ps);

	pswap_destroy(&ps);

	TEST_ASSERT_NULL(ps);
}

TEST_GROUP_RUNNER(pswap_destroy)
{
	RUN_TEST_CASE(pswap_destroy, Destroy);
}
