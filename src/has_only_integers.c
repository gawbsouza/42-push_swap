/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_only_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:09:03 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/16 02:15:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_integer(const char *str);
static int	is_overflow(const char *str);

int	has_only_integers(char *const *list, size_t size)
{
	if (!list || !*list || !size)
		return (0);
	while (size--)
	{
		if (!is_integer(list[size]))
			return (0);
		if (is_overflow(list[size]))
			return (0);
	}
	return (1);
}

static int	is_integer(const char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	is_overflow(const char *str)
{
	int		num;
	char	*num_str;
	int		result;

	if (!str)
		return (0);
	if (ft_strncmp(str, "+0", 3) == 0 || ft_strncmp(str, "-0", 3) == 0)
		return (0);
	if (*str == '+')
		str++;
	if (!*str)
		return (0);
	num = ft_atoi(str);
	num_str = ft_itoa(num);
	result = (ft_strncmp(str, num_str, ft_strlen(num_str) + 1) != 0);
	free(num_str);
	return (result);
}
