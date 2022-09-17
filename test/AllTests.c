/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 01:19:41 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"

static	void	runAllTests(void)
{
	RUN_TEST_GROUP(stack_create);
	RUN_TEST_GROUP(stack_destroy);
	RUN_TEST_GROUP(stack_push);
	RUN_TEST_GROUP(stack_pop);
	RUN_TEST_GROUP(stack_swap);
	RUN_TEST_GROUP(stack_rotate_up);
	RUN_TEST_GROUP(stack_rotate_down);
	RUN_TEST_GROUP(pswap_create);
	RUN_TEST_GROUP(pswap_destroy);
	RUN_TEST_GROUP(sa);
	RUN_TEST_GROUP(sb);
	RUN_TEST_GROUP(ss);
	RUN_TEST_GROUP(pa);
	RUN_TEST_GROUP(pb);
	RUN_TEST_GROUP(rotate_up_cmds);
	RUN_TEST_GROUP(rotate_down_cmds);
	RUN_TEST_GROUP(pswap_sort);
	RUN_TEST_GROUP(stack_pos_ordered);
	RUN_TEST_GROUP(move_n_items_from_a);
	RUN_TEST_GROUP(add_msg_to_log);
	RUN_TEST_GROUP(stack_is_ordered);
	RUN_TEST_GROUP(pswap_sort_playback);
	RUN_TEST_GROUP(has_duplicate_strings);
	RUN_TEST_GROUP(has_only_integers);
	RUN_TEST_GROUP(is_valid_move);
	RUN_TEST_GROUP(selection_sort);
}

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}
