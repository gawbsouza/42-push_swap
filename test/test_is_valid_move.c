/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:24:58 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 22:35:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(is_valid_move);

TEST_SETUP(is_valid_move)
{
}

TEST_TEAR_DOWN(is_valid_move)
{
}

TEST(is_valid_move, NullPointerString)
{
	TEST_ASSERT_FALSE(is_valid_move(NULL));
}

TEST(is_valid_move, WithInvalidMove)
{
	TEST_ASSERT_FALSE(is_valid_move(" "));
	TEST_ASSERT_FALSE(is_valid_move("ha"));
	TEST_ASSERT_FALSE(is_valid_move("42"));
}

TEST(is_valid_move, WithValidMove)
{
	TEST_ASSERT_TRUE(is_valid_move("pa"));
	TEST_ASSERT_TRUE(is_valid_move("pb"));
	TEST_ASSERT_TRUE(is_valid_move("sa"));
	TEST_ASSERT_TRUE(is_valid_move("sb"));
	TEST_ASSERT_TRUE(is_valid_move("ss"));
	TEST_ASSERT_TRUE(is_valid_move("ra"));
	TEST_ASSERT_TRUE(is_valid_move("rb"));
	TEST_ASSERT_TRUE(is_valid_move("rr"));
	TEST_ASSERT_TRUE(is_valid_move("rra"));
	TEST_ASSERT_TRUE(is_valid_move("rrb"));
	TEST_ASSERT_TRUE(is_valid_move("rrr"));
}

TEST_GROUP_RUNNER(is_valid_move)
{
	RUN_TEST_CASE(is_valid_move, NullPointerString);
	RUN_TEST_CASE(is_valid_move, WithInvalidMove);
	RUN_TEST_CASE(is_valid_move, WithValidMove);
}
