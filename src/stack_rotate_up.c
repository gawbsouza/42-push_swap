/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:40:46 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 14:28:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate_up(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->items;
	stack->items = tmp->next;
	stack->last->next = tmp;
	stack->last = tmp;
	stack->last->next = NULL;
}
