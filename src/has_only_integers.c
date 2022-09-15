/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_only_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:09:03 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/14 23:36:19 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_integer(const char *str);

int	has_only_integers(char *const *list, size_t size)
{
	if (!list || !*list || !size)
		return (0);
	while (size--)
	{
		if (!is_integer(list[size]))
			return (0);
	}
	return (1);
}

static int	is_integer(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
