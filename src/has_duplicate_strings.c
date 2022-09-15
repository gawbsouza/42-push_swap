/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:54:28 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/14 23:00:31 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate_strings(char *const *list, size_t size)
{
	char	*str;
	int		count;
	size_t	i;
	size_t	k;

	if (!list || !*list || size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		k = 0;
		count = 0;
		str = list[i];
		while (k < size)
		{
			if (ft_strncmp(list[k], str, ft_strlen(str) + 1) == 0)
				count++;
			if (count > 1)
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
