/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:45:05 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 22:05:56 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->items || !stack->items->next)
		return ;
	tmp = stack->items->next;
	stack->items->next = tmp->next;
	tmp->next = stack->items;
	stack->items = tmp;
}
