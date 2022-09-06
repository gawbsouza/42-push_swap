/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:10:40 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/06 11:25:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_node
{
	unsigned int	value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*items;
}	t_stack;

t_stack	*stack_create(void);

#endif
