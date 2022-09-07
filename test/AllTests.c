/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 17:24:38 by gasouza          ###   ########.fr       */
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
}

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}
