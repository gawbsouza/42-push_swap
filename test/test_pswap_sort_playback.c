/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pswap_sort_playback.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:17:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/13 10:36:17 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "push_swap.h"

TEST_GROUP(pswap_sort_playback);

static t_pswap *pswap;

TEST_SETUP(pswap_sort_playback)
{
	pswap = pswap_create();
	
	TEST_ASSERT_NOT_NULL(pswap);
}

TEST_TEAR_DOWN(pswap_sort_playback)
{
	pswap_destroy(&pswap);
}

TEST(pswap_sort_playback, NullInitialization)
{
	pswap_sort_playback(NULL, NULL);
	pswap_sort_playback(pswap, NULL);
	pswap_sort_playback(pswap, "");
	pswap_sort_playback(NULL, "pa pb ss sa");

	TEST_ASSERT_NOT_NULL(pswap);
}

TEST(pswap_sort_playback, PaMove)
{
	stack_push(pswap->b, 42);

	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(1, pswap->b->size);

	pswap_sort_playback(pswap, "pa");
	
	TEST_ASSERT_EQUAL_INT(1, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
}

TEST(pswap_sort_playback, PbMove)
{
	stack_push(pswap->a, 42);

	TEST_ASSERT_EQUAL_INT(1, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	pswap_sort_playback(pswap, "pb");
	
	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(1, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, SaMove)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	pswap_sort_playback(pswap, "sa");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
}

TEST(pswap_sort_playback, SbMove)
{
	stack_push(pswap->b, 64);
	stack_push(pswap->b, 42);
	stack_push(pswap->b, 21);

	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "sb");
	
	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, SsMove)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	stack_push(pswap->b, 154);
	stack_push(pswap->b, 102);
	stack_push(pswap->b, 51);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "ss");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	
	TEST_ASSERT_EQUAL_INT(102, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(51, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, RaMove)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	pswap_sort_playback(pswap, "ra");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
}

TEST(pswap_sort_playback, RbMove)
{
	stack_push(pswap->b, 64);
	stack_push(pswap->b, 42);
	stack_push(pswap->b, 21);

	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "rb");
	
	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, RrMove)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	stack_push(pswap->b, 154);
	stack_push(pswap->b, 102);
	stack_push(pswap->b, 51);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "rr");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
	
	TEST_ASSERT_EQUAL_INT(102, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(51, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, RraMove)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	pswap_sort_playback(pswap, "rra");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
}

TEST(pswap_sort_playback, RrbMove)
{
	stack_push(pswap->b, 64);
	stack_push(pswap->b, 42);
	stack_push(pswap->b, 21);

	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "rrb");
	
	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, RrrMove)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	stack_push(pswap->b, 154);
	stack_push(pswap->b, 102);
	stack_push(pswap->b, 51);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "rrr");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	
	TEST_ASSERT_EQUAL_INT(154, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(51, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(102, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, MultiMoves_case1)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	pswap_sort_playback(pswap, "sa\nra\nsa\nrra\n");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(0, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
}

TEST(pswap_sort_playback, MultiMoves_case2)
{
	stack_push(pswap->b, 154);
	stack_push(pswap->b, 102);
	stack_push(pswap->b, 51);

	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "sb\nrb\nsb\nrrb\n");
	
	TEST_ASSERT_EQUAL_INT(0, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);
	
	TEST_ASSERT_EQUAL_INT(102, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(51, stack_pop(pswap->b));
}

TEST(pswap_sort_playback, MultiMoves_case3)
{
	stack_push(pswap->a, 64);
	stack_push(pswap->a, 42);
	stack_push(pswap->a, 21);

	stack_push(pswap->b, 154);
	stack_push(pswap->b, 102);
	stack_push(pswap->b, 51);

	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	pswap_sort_playback(pswap, "rr\nss\nrrr\n");
	
	TEST_ASSERT_EQUAL_INT(3, pswap->a->size);
	TEST_ASSERT_EQUAL_INT(3, pswap->b->size);

	TEST_ASSERT_EQUAL_INT(21, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(64, stack_pop(pswap->a));
	TEST_ASSERT_EQUAL_INT(42, stack_pop(pswap->a));
	
	TEST_ASSERT_EQUAL_INT(51, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(154, stack_pop(pswap->b));
	TEST_ASSERT_EQUAL_INT(102, stack_pop(pswap->b));
}

TEST_GROUP_RUNNER(pswap_sort_playback)
{
	RUN_TEST_CASE(pswap_sort_playback, NullInitialization);
	RUN_TEST_CASE(pswap_sort_playback, PaMove);
	RUN_TEST_CASE(pswap_sort_playback, PbMove);
	RUN_TEST_CASE(pswap_sort_playback, SaMove);
	RUN_TEST_CASE(pswap_sort_playback, SbMove);
	RUN_TEST_CASE(pswap_sort_playback, SsMove);
	RUN_TEST_CASE(pswap_sort_playback, RaMove);
	RUN_TEST_CASE(pswap_sort_playback, RbMove);
	RUN_TEST_CASE(pswap_sort_playback, RrMove);
	RUN_TEST_CASE(pswap_sort_playback, RraMove);
	RUN_TEST_CASE(pswap_sort_playback, RrbMove);
	RUN_TEST_CASE(pswap_sort_playback, RrrMove);
	RUN_TEST_CASE(pswap_sort_playback, MultiMoves_case1);
	RUN_TEST_CASE(pswap_sort_playback, MultiMoves_case2);
	RUN_TEST_CASE(pswap_sort_playback, MultiMoves_case3);
}
