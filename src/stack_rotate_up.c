/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:40:46 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 11:24:29 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate_up(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack || !stack->items || !stack->items->next)
		return ;
	last = stack->items;
	while (last->next)
		last = last->next;
	first = stack->items;
	stack->items = first->next;
	first->next = NULL;
	last->next = first;
}
