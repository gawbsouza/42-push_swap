/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:26:47 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 21:27:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_args(int argc, char **argv)
{
	if (!has_only_integers(argv, argc))
		return (0);
	if (has_duplicate_strings(argv, argc))
		return (0);
	return (1);
}
