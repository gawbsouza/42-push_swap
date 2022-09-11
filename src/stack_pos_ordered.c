/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pos_ordered.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:15:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 07:28:19 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_pos_ordered(t_stack *stack, size_t pos)
{
	size_t	pos_count;
	t_node	*item;

	if (!stack || pos == 0 || pos > stack->size)
		return (-1);
	item = stack->items;
	pos_count = 1;
	while (pos_count < pos)
	{
		item = item->next;
		pos_count++;
	}
	if (item->next && item->value > item->next->value)
		return (0);
	return (1);
}
