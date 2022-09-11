/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_msg_to_log.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 07:43:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 08:18:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(add_msg_to_log);

static char *test_log;

TEST_SETUP(add_msg_to_log)
{
	test_log = NULL;
}

TEST_TEAR_DOWN(add_msg_to_log)
{
	free(test_log);
}

TEST(add_msg_to_log, NullPointerLog)
{
	add_msg_to_log("msg", &test_log);

	TEST_ASSERT_EQUAL_STRING(test_log, "msg");
}

TEST(add_msg_to_log, NullPointerMsg)
{
	add_msg_to_log(NULL, &test_log);

	TEST_ASSERT_NULL(test_log);
}

TEST(add_msg_to_log, WithNoPreviousLogMsg)
{
	add_msg_to_log("msg", &test_log);

	TEST_ASSERT_NOT_NULL(test_log);
	TEST_ASSERT_EQUAL_STRING(test_log, "msg");
}

TEST(add_msg_to_log, WithPreviousLogMsg)
{
	test_log = ft_strdup("prev");

	TEST_ASSERT_EQUAL_STRING(test_log, "prev");

	add_msg_to_log(" msg", &test_log);
	TEST_ASSERT_EQUAL_STRING(test_log, "prev msg");
	
	add_msg_to_log(" testing ", &test_log);
	TEST_ASSERT_EQUAL_STRING(test_log, "prev msg testing ");
}

TEST_GROUP_RUNNER(add_msg_to_log)
{
	RUN_TEST_CASE(add_msg_to_log, NullPointerLog);
	RUN_TEST_CASE(add_msg_to_log, NullPointerMsg);
	RUN_TEST_CASE(add_msg_to_log, WithNoPreviousLogMsg);
	RUN_TEST_CASE(add_msg_to_log, WithPreviousLogMsg);
}
