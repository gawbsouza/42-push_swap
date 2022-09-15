/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_has_only_integers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:05:05 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 10:29:46 by gasouza          ###   ########.fr       */
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
	char *list1[] = {NULL};
	TEST_ASSERT_FALSE(has_only_integers(NULL, 1));
	TEST_ASSERT_FALSE(has_only_integers(list1, 1));
	char *list2[] = {""};
	TEST_ASSERT_FALSE(has_only_integers(list2, 1));
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

TEST(has_only_integers, WithSignalIntegers)
{
	char *list1[] = {"-42", "+100", "+0", "-0"};
	TEST_ASSERT_TRUE(has_only_integers(list1, 4));

	char *list2[] = {"--42", "++100"};
	TEST_ASSERT_FALSE(has_only_integers(list2, 2));

	char *list3[] = {"-", "+"};
	TEST_ASSERT_FALSE(has_only_integers(list3, 2));
}

TEST(has_only_integers, NumberGreaterThanIntMax)
{
	char *int_max = ft_itoa(INT_MAX);
	char *list1[] = {int_max};
	TEST_ASSERT_TRUE(has_only_integers(list1, 1));

	char *out_int_max = ft_strjoin(int_max, "91");
	char *list2[] = {out_int_max};
	TEST_ASSERT_FALSE(has_only_integers(list2, 1));
	
	free(int_max);
	free(out_int_max);
}

TEST(has_only_integers, NumberLessThanIntMin)
{
	char *int_min = ft_itoa(INT_MIN);
	char *list1[] = {int_min};
	TEST_ASSERT_TRUE(has_only_integers(list1, 1));

	char *under_int_min = ft_strjoin(int_min, "91");
	char *list2[] = {under_int_min};
	TEST_ASSERT_FALSE(has_only_integers(list2, 1));
	
	free(int_min);
	free(under_int_min);
}

TEST_GROUP_RUNNER(has_only_integers)
{
	RUN_TEST_CASE(has_only_integers, EmptyList);
	RUN_TEST_CASE(has_only_integers, SizeZero);
	RUN_TEST_CASE(has_only_integers, WithOneValidInteger);
	RUN_TEST_CASE(has_only_integers, WithTwoValidInteger);
	RUN_TEST_CASE(has_only_integers, WithTwoInvalidInteger);
	RUN_TEST_CASE(has_only_integers, WithMultiplesValidsAndOneInvalidInteger);
	RUN_TEST_CASE(has_only_integers, WithSignalIntegers);
	RUN_TEST_CASE(has_only_integers, NumberGreaterThanIntMax);
	RUN_TEST_CASE(has_only_integers, NumberLessThanIntMin);
}
