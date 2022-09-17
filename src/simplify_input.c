/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:44:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 16:42:59 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*str_arr_to_int_arr(char **arr, int size);
static int	*simplify(int *ori, int *ord, int size);

int	*simplify_input(char **arr, int size)
{
	int		*input;
	int		*copy;
	int		*result;

	input = str_arr_to_int_arr(arr, size);
	copy = str_arr_to_int_arr(arr, size);
	result = NULL;
	if (input && copy)
	{
		selection_sort(input, size);
		result = simplify(input, copy, size);
	}
	free(input);
	free(copy);
	return (result);
}

static int	*str_arr_to_int_arr(char **arr, int size)
{
	int	*result;
	int	i;

	if (!arr || size < 1)
		return (NULL);
	result = (int *) malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = ft_atoi(arr[i]);
		i++;
	}
	return (result);
}

static int	*simplify(int *ori, int *ord, int size)
{
	int	*result;
	int	i;
	int	j;

	if (!ori || !ord || size < 1)
		return (NULL);
	result = (int *) malloc(sizeof(int) * size);
	if (result)
	{
		i = 0;
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				if (ord[i] == ori[j])
					result[i] = j;
				j++;
			}
			i++;
		}
	}
	return (result);
}
