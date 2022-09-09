/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:07:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:10:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate_down(t_stack *stack)
{
	t_node	*penult;

	if (!stack || stack->size < 2)
		return ;
	penult = stack->items;
	while (penult->next != stack->last)
		penult = penult->next;
	stack->last->next = stack->items;
	stack->items = stack->last;
	stack->last = penult;
	stack->last->next = NULL;
}
