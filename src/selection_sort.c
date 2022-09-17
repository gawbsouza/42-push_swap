/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:21:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 11:24:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
		{
			tmp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = tmp;
		}
		i++;
	}
}
