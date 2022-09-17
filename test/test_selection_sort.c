/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_selection_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:14:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 01:20:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(selection_sort);

TEST_SETUP(selection_sort)
{
}

TEST_TEAR_DOWN(selection_sort)
{
}

TEST(selection_sort, ThreeElementsUnordered)
{
	int nums[] = {5, -15, 9};

	selection_sort(nums, 3);

	TEST_ASSERT_EQUAL_INT(-15, nums[0]);
	TEST_ASSERT_EQUAL_INT(5, nums[1]);
	TEST_ASSERT_EQUAL_INT(9, nums[2]);
}

TEST_GROUP_RUNNER(selection_sort)
{
	RUN_TEST_CASE(selection_sort, ThreeElementsUnordered);
}
