/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_has_duplicate_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:48:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/14 23:02:15 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(has_duplicate_strings);

TEST_SETUP(has_duplicate_strings)
{
}

TEST_TEAR_DOWN(has_duplicate_strings)
{
}

TEST(has_duplicate_strings, EmptyList)
{
	char **list = NULL;

	TEST_ASSERT_FALSE(has_duplicate_strings(NULL, 1));
	TEST_ASSERT_FALSE(has_duplicate_strings(list, 1));
}

TEST(has_duplicate_strings, OneItemAndSizeZero)
{
	char *list[] = {"42"};
	TEST_ASSERT_FALSE(has_duplicate_strings(list, 0));
}

TEST(has_duplicate_strings, OneItemAndSizeOne)
{
	char *list[] = {"42"};
	TEST_ASSERT_FALSE(has_duplicate_strings(list, 1));
}

TEST(has_duplicate_strings, TwoValuesWithNoDuplicatedItems)
{
	char *list[] = {"42", "school"};
	TEST_ASSERT_FALSE(has_duplicate_strings(list, 2));
}

TEST(has_duplicate_strings, TwoValuesWithDuplicatedItems)
{
	char *list[] = {"school", "school"};
	TEST_ASSERT_TRUE(has_duplicate_strings(list, 2));
}

TEST(has_duplicate_strings, ThreeValuesWithNoDuplicatedItems)
{
	char *list[] = {"42", "school", "galaxy"};
	TEST_ASSERT_FALSE(has_duplicate_strings(list, 3));
}

TEST(has_duplicate_strings, ThreeValuesWithDuplicatedItems)
{
	char *list[] = {"42", "galaxy", "galaxy"};
	TEST_ASSERT_TRUE(has_duplicate_strings(list, 3));
}

TEST(has_duplicate_strings, FiveValuesWithDuplicatedItems)
{
	char *list[] = {"42", "galaxy", "star", "rocket", "galaxy"};
	TEST_ASSERT_TRUE(has_duplicate_strings(list, 5));
}

TEST_GROUP_RUNNER(has_duplicate_strings)
{
	RUN_TEST_CASE(has_duplicate_strings, EmptyList);
	RUN_TEST_CASE(has_duplicate_strings, OneItemAndSizeZero);
	RUN_TEST_CASE(has_duplicate_strings, OneItemAndSizeOne);
	RUN_TEST_CASE(has_duplicate_strings, TwoValuesWithNoDuplicatedItems);
	RUN_TEST_CASE(has_duplicate_strings, TwoValuesWithDuplicatedItems);
	RUN_TEST_CASE(has_duplicate_strings, ThreeValuesWithNoDuplicatedItems);
	RUN_TEST_CASE(has_duplicate_strings, ThreeValuesWithDuplicatedItems);
	RUN_TEST_CASE(has_duplicate_strings, FiveValuesWithDuplicatedItems);
}
