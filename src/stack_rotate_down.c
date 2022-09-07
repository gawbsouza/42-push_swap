/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:07:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 11:22:07 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate_down(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*penult;

	if (!stack || !stack->items || !stack->items->next)
		return ;
	first = stack->items;
	last = first;
	penult = first;
	while (last->next)
	{
		penult = last;
		last = last->next;
	}
	last->next = first;
	stack->items = last;
	penult->next = NULL;
}
