/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:39:27 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 11:24:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_valid_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_pswap	*pswap;
	char	*result;

	if (argc < 2)
		return (0);
	if (!is_valid_args(--argc, ++argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	pswap = pswap_create();
	while (argc--)
		stack_push(pswap->a, ft_atoi(argv[argc]));
	result = pswap_sort(pswap);
	if (result)
		ft_putstr_fd(result, 1);
	pswap_destroy(&pswap);
	return (0);
}

static int	is_valid_args(int argc, char **argv)
{
	if (!has_only_integers(argv, argc))
		return (0);
	if (has_duplicate_strings(argv, argc))
		return (0);
	return (1);
}
