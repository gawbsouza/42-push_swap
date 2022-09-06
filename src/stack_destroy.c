/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:01:58 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 14:07:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node_destroy(t_node *node)
{
	if (!node)
		return ;
	if (node->next)
		node_destroy(node->next);
	free(node->next);
	free(node);
}

void	stack_destroy(t_stack **stack)
{
	if (!stack || !*stack)
		return ;

	node_destroy((*stack)->items);
	free((*stack));
	(*stack) = NULL;
}
