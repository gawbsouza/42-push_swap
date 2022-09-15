/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:10:40 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/14 22:53:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*items;
	t_node	*last;
	size_t	size;
}	t_stack;

typedef struct s_pswap
{
	t_stack	*a;
	t_stack	*b;
}	t_pswap;

t_stack	*stack_create(void);
void	stack_destroy(t_stack **stack);
void	stack_push(t_stack *stack, int value);
int		stack_pop(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_rotate_down(t_stack *stack);
int		stack_pos_ordered(t_stack *stack, size_t pos);
int		stack_is_ordered(t_stack *stack);
t_pswap	*pswap_create(void);
void	pswap_destroy(t_pswap **pswap);
char	*pswap_sort(t_pswap *pswap);
void	sa(t_pswap *pswap);
void	sb(t_pswap *pswap);
void	ss(t_pswap *pswap);
void	pa(t_pswap *pswap);
void	pb(t_pswap *pswap);
void	ra(t_pswap *pswap);
void	rb(t_pswap *pswap);
void	rr(t_pswap *pswap);
void	rra(t_pswap *pswap);
void	rrb(t_pswap *pswap);
void	rrr(t_pswap *pswap);
void	add_msg_to_log(char *msg, char **log);
void	move_n_items_from_a(t_pswap *pswap, size_t n, char **log);
void	pswap_sort_playback(t_pswap *pswap, const char *moves);
int		has_duplicate_strings(char *const *list, size_t size);

#endif
