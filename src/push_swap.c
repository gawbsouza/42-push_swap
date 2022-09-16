/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:39:27 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 21:33:45 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pswap	*pswap;
	char	*result;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!is_valid_args(--argc, ++argv))
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	pswap = pswap_create();
	while (argc--)
		stack_push(pswap->a, ft_atoi(argv[argc]));
	result = pswap_sort(pswap);
	if (result)
		ft_putstr_fd(result, 1);
	pswap_destroy(&pswap);
	free(result);
	exit(EXIT_SUCCESS);
}
