/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_move_n_items_from_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:54:39 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 07:40:05 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(move_n_items_from_a);

static t_pswap *ps;
static char *sort_log;

TEST_SETUP(move_n_items_from_a)
{
	sort_log = NULL;
	ps = pswap_create();

	TEST_ASSERT_NOT_NULL(ps);
}

TEST_TEAR_DOWN(move_n_items_from_a)
{
	free(sort_log);
	pswap_destroy(&ps);
}

TEST(move_n_items_from_a, NullPswapPointer)
{
	move_n_items_from_a(NULL, 1, &sort_log);

	TEST_ASSERT_NULL(sort_log);
}

TEST(move_n_items_from_a, EmptyStackA)
{
	move_n_items_from_a(ps, 1, &sort_log);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_NULL(sort_log);
}

TEST(move_n_items_from_a, InvalidQuantityToMove)
{
	move_n_items_from_a(ps, 1, &sort_log);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_NULL(sort_log);
	
	stack_push(ps->a, 42);
	move_n_items_from_a(ps, 0, &sort_log);
	move_n_items_from_a(ps, 2, &sort_log);
	move_n_items_from_a(ps, 5, &sort_log);

	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(0, ps->b->size);
	TEST_ASSERT_NULL(sort_log);
}

TEST(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeOne)
{
	stack_push(ps->a, 42);
	move_n_items_from_a(ps, 1, &sort_log);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);
	TEST_ASSERT_NOT_NULL(sort_log);
	TEST_ASSERT_EQUAL_STRING("pb\n", sort_log);
}

TEST(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeTwo)
{
	stack_push(ps->a, 42);
	stack_push(ps->a, 21);
	move_n_items_from_a(ps, 1, &sort_log);

	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(1, ps->b->size);
	TEST_ASSERT_NOT_NULL(sort_log);
	TEST_ASSERT_EQUAL_STRING("pb\n", sort_log);
}

TEST(move_n_items_from_a, MoveTwoItemsFromAWhenAIsSizeTwo)
{
	stack_push(ps->a, 42);
	stack_push(ps->a, 21);
	move_n_items_from_a(ps, 2, &sort_log);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(2, ps->b->size);
	TEST_ASSERT_NOT_NULL(sort_log);
	TEST_ASSERT_EQUAL_STRING("pb\npb\n", sort_log);
}

TEST(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeOneAndBSizeOne)
{
	stack_push(ps->a, 42);

	stack_push(ps->b, 21);
	move_n_items_from_a(ps, 1, &sort_log);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(2, ps->b->size);
	TEST_ASSERT_NOT_NULL(sort_log);
	TEST_ASSERT_EQUAL_STRING("pb\n", sort_log);
}

TEST(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeOneAndBSizeTwo)
{
	stack_push(ps->a, 42);
	stack_push(ps->b, 21);

	stack_push(ps->b, 64);
	move_n_items_from_a(ps, 1, &sort_log);

	TEST_ASSERT_EQUAL_INT(0, ps->a->size);
	TEST_ASSERT_EQUAL_INT(3, ps->b->size);
	TEST_ASSERT_NOT_NULL(sort_log);
	TEST_ASSERT_EQUAL_STRING("pb\n", sort_log);
}

TEST(move_n_items_from_a, MoveMultiItemsFromA)
{
	stack_push(ps->a, 51);
	stack_push(ps->a, 102);
	stack_push(ps->a, 42);
	stack_push(ps->a, 21);

	stack_push(ps->b, 64);
	move_n_items_from_a(ps, 3, &sort_log);

	TEST_ASSERT_EQUAL_INT(1, ps->a->size);
	TEST_ASSERT_EQUAL_INT(4, ps->b->size);
	TEST_ASSERT_NOT_NULL(sort_log);
	TEST_ASSERT_EQUAL_STRING("pb\npb\npb\n", sort_log);
}

TEST_GROUP_RUNNER(move_n_items_from_a)
{
	RUN_TEST_CASE(move_n_items_from_a, NullPswapPointer);
	RUN_TEST_CASE(move_n_items_from_a, EmptyStackA);
	RUN_TEST_CASE(move_n_items_from_a, InvalidQuantityToMove);
	RUN_TEST_CASE(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeOne);
	RUN_TEST_CASE(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeTwo);
	RUN_TEST_CASE(move_n_items_from_a, MoveTwoItemsFromAWhenAIsSizeTwo);
	RUN_TEST_CASE(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeOneAndBSizeOne);
	RUN_TEST_CASE(move_n_items_from_a, MoveOneItemFromAWhenAIsSizeOneAndBSizeTwo);
	RUN_TEST_CASE(move_n_items_from_a, MoveMultiItemsFromA);
}
