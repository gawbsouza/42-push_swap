/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_has_only_integers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:05:05 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/14 23:35:07 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(has_only_integers);

TEST_SETUP(has_only_integers)
{
}

TEST_TEAR_DOWN(has_only_integers)
{
}

TEST(has_only_integers, EmptyList)
{
	char *list[] = {NULL};
	TEST_ASSERT_FALSE(has_only_integers(NULL, 1));
	TEST_ASSERT_FALSE(has_only_integers(list, 1));
}

TEST(has_only_integers, SizeZero)
{
	char *list[] = {"42"};
	TEST_ASSERT_FALSE(has_only_integers(list, 0));
}

TEST(has_only_integers, WithOneValidInteger)
{
	char *list[] = {"42"};
	TEST_ASSERT_TRUE(has_only_integers(list, 1));
}

TEST(has_only_integers, WithOneInvalidInteger)
{
	char *list[] = {"school"};
	TEST_ASSERT_FALSE(has_only_integers(list, 1));
}

TEST(has_only_integers, WithTwoValidInteger)
{
	char *list[] = {"42", "20909"};
	TEST_ASSERT_TRUE(has_only_integers(list, 2));
}

TEST(has_only_integers, WithTwoInvalidInteger)
{
	char *list[] = {"school", "galaxy"};
	TEST_ASSERT_FALSE(has_only_integers(list, 2));
}

TEST(has_only_integers, WithMultiplesValidsAndOneInvalidInteger)
{
	char *list1[] = {"9234", "41", "42", "59", "100bug", "64"};
	TEST_ASSERT_FALSE(has_only_integers(list1, 6));
	
	char *list2[] = {"54", " _", "100"};
	TEST_ASSERT_FALSE(has_only_integers(list2, 3));
	
	char *list3[] = {"47", "10923", "%$", "100"};
	TEST_ASSERT_FALSE(has_only_integers(list3, 4));
}

TEST_GROUP_RUNNER(has_only_integers)
{
	RUN_TEST_CASE(has_only_integers, EmptyList);
	RUN_TEST_CASE(has_only_integers, SizeZero);
	RUN_TEST_CASE(has_only_integers, WithOneValidInteger);
	RUN_TEST_CASE(has_only_integers, WithTwoValidInteger);
	RUN_TEST_CASE(has_only_integers, WithTwoInvalidInteger);
	RUN_TEST_CASE(has_only_integers, WithMultiplesValidsAndOneInvalidInteger);
}
