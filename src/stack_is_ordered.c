/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 08:30:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 09:09:47 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_ordered(t_stack *stack)
{
	t_node	*item;

	if (!stack)
		return (0);
	item = stack->items;
	while (item && item->next)
	{
		if (item->value > item->next->value)
			return (0);
		item = item->next;
	}
	return (1);
}
