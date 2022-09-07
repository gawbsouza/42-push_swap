/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:10:40 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 12:07:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	unsigned int	value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*items;
}	t_stack;

typedef struct s_pswap
{
	t_stack	*a;
	t_stack	*b;
}	t_pswap;

t_stack	*stack_create(void);
void	stack_destroy(t_stack **stack);
void	stack_push(t_stack *stack, unsigned int value);
t_node	*stack_pop(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_rotate_down(t_stack *stack);
t_pswap	*pswap_create(t_stack *a, t_stack *b);
void	pswap_destroy(t_pswap **pswap);

#endif
