/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:35:41 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 09:30:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int		pop;

	node = stack->items;
	if (node)
		stack->items = node->next;
	if (!stack->items)
		stack->last = NULL;
	pop = node->value;
	free(node);
	stack->size--;
	return (pop);
}
