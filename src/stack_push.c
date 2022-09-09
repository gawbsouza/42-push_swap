/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:04:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 08:49:08 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*node_create(int value)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (node)
	{
		node->value = value;
		node->next = NULL;
	}
	return (node);
}

void	stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = node_create(value);
	if (new_node)
	{
		new_node->next = stack->items;
		stack->items = new_node;
		if (!stack->last)
			stack->last = new_node;
		stack->size++;
	}
}
