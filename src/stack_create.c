/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:26:07 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 11:28:18 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (stack)
		stack->items = NULL;
	return (stack);
}
