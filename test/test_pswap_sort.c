/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pswap_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:45:47 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/13 11:06:59 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pswap_sort);

static t_pswap *ps;
static char *sort_log;

TEST_SETUP(pswap_sort)
{
	ps = pswap_create();
	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(pswap_sort)
{
	free(sort_log);
	pswap_destroy(&ps);
}

TEST(pswap_sort, EmptyStacks)
{
	sort_log = pswap_sort(ps);

	TEST_ASSERT_NULL(sort_log);
}

TEST(pswap_sort, StackWithOneItem)
{
	stack_push(ps->a, 1);

	sort_log = pswap_sort(ps);

	TEST_ASSERT_NULL(sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithTwoOrderedItems)
{
	stack_push(ps->a, 2);
	stack_push(ps->a, 1);

	// 1 2
	sort_log = pswap_sort(ps);

	TEST_ASSERT_NULL(sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithTwoUnorderedItems)
{
	stack_push(ps->a, 1);
	stack_push(ps->a, 2);

	// 2 1
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithThreeOrderedItems)
{
	stack_push(ps->a, 3);
	stack_push(ps->a, 2);
	stack_push(ps->a, 1);

	// 1 2 3
	sort_log = pswap_sort(ps);

	TEST_ASSERT_NULL(sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithThreeUnorderedItems_case1)
{
	stack_push(ps->a, 2);
	stack_push(ps->a, 1);
	stack_push(ps->a, 3);

	// 3 1 2
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithThreeUnorderedItems_case2)
{
	stack_push(ps->a, 1);
	stack_push(ps->a, 2);
	stack_push(ps->a, 3);

	// 3 2 1 
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\nsa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithThreeUnorderedItems_case3)
{
	stack_push(ps->a, 3);
	stack_push(ps->a, 1);
	stack_push(ps->a, 2);

	// 2 1 3
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("sa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithFourOrderedItems)
{
	stack_push(ps->a, 4);
	stack_push(ps->a, 3);
	stack_push(ps->a, 2);
	stack_push(ps->a, 1);

	// 1 2 3 4
	sort_log = pswap_sort(ps);

	TEST_ASSERT_NULL(sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithFourUnorderedItems_case1)
{
	stack_push(ps->a, 3);
	stack_push(ps->a, 2);
	stack_push(ps->a, 1);
	stack_push(ps->a, 4);

	// 4 1 2 3
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithFourUnorderedItems_case2)
{
	stack_push(ps->a, 3);
	stack_push(ps->a, 1);
	stack_push(ps->a, 2);
	stack_push(ps->a, 4);

	// 4 2 1 3
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\nsa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithFourUnorderedItems_case3)
{
	stack_push(ps->a, 2);
	stack_push(ps->a, 1);
	stack_push(ps->a, 3);
	stack_push(ps->a, 4);

	// 4 3 1 2
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\nsa\npb\nsa\npa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithFiveUnorderedItems_case1)
{
	stack_push(ps->a, 3);
	stack_push(ps->a, 4);
	stack_push(ps->a, 2);
	stack_push(ps->a, 5);
	stack_push(ps->a, 1);

	// 1 5 2 4 3
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("pb\nra\npa\npb\npb\nsa\npa\npa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithFiveUnorderedItems_case2)
{
	stack_push(ps->a, 1);
	stack_push(ps->a, 2);
	stack_push(ps->a, 3);
	stack_push(ps->a, 4);
	stack_push(ps->a, 5);

	// 5 4 3 2 1
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("ra\nsa\npb\nsa\npa\nsa\npb\npb\nsa\npa\nsa\npa\nsa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithSixUnorderedItems)
{
	stack_push(ps->a, 3);
	stack_push(ps->a, 2);
	stack_push(ps->a, 5);
	stack_push(ps->a, 1);
	stack_push(ps->a, 6);
	stack_push(ps->a, 4);

	// 4 6 1 5 2 3
	sort_log = pswap_sort(ps);

	TEST_ASSERT_EQUAL_STRING("pb\nra\npa\nsa\npb\npb\nsa\npa\nsa\npa\npb\npb\npb\nsa\npa\nsa\npa\npa\n", sort_log);
	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST(pswap_sort, StackWithTenUnorderedItems)
{
	stack_push(ps->a, 9);
	stack_push(ps->a, 8);
	stack_push(ps->a, 10);
	stack_push(ps->a, 3);
	stack_push(ps->a, 2);
	stack_push(ps->a, 5);
	stack_push(ps->a, 1);
	stack_push(ps->a, 6);
	stack_push(ps->a, 4);
	stack_push(ps->a, 7);

	// 7 4 6 1 5 2 3 10 8 9
	sort_log = pswap_sort(ps);

	TEST_ASSERT_TRUE(stack_is_ordered(ps->a));
}

TEST_GROUP_RUNNER(pswap_sort)
{
	RUN_TEST_CASE(pswap_sort, EmptyStacks);
	RUN_TEST_CASE(pswap_sort, StackWithOneItem);
	RUN_TEST_CASE(pswap_sort, StackWithTwoOrderedItems);
	RUN_TEST_CASE(pswap_sort, StackWithTwoUnorderedItems);
	RUN_TEST_CASE(pswap_sort, StackWithThreeOrderedItems);
	RUN_TEST_CASE(pswap_sort, StackWithThreeUnorderedItems_case1);
	RUN_TEST_CASE(pswap_sort, StackWithThreeUnorderedItems_case2);
	RUN_TEST_CASE(pswap_sort, StackWithThreeUnorderedItems_case3);
	RUN_TEST_CASE(pswap_sort, StackWithFourOrderedItems);
	RUN_TEST_CASE(pswap_sort, StackWithFourUnorderedItems_case1);
	RUN_TEST_CASE(pswap_sort, StackWithFourUnorderedItems_case2);
	RUN_TEST_CASE(pswap_sort, StackWithFourUnorderedItems_case3);
	RUN_TEST_CASE(pswap_sort, StackWithFiveUnorderedItems_case1);
	RUN_TEST_CASE(pswap_sort, StackWithFiveUnorderedItems_case2);
	RUN_TEST_CASE(pswap_sort, StackWithSixUnorderedItems);
	RUN_TEST_CASE(pswap_sort, StackWithTenUnorderedItems);
}

