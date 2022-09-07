/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:35:41 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 21:35:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (NULL);
	node = stack->items;
	if (node)
		stack->items = node->next;
	node->next = NULL;
	return (node);
}
