/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:05:39 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 07:35:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_swap_a(t_pswap *pswap, char **log)
{
	t_node	*first;
	t_node	*second;

	if (!pswap || !log)
		return ;
	first = pswap->a->items;
	second = first->next;
	if (second && first->value > second->value)
	{
		add_msg_to_log("sa\n", log);
		sa(pswap);
	}
}

static void	try_rotate_up_a(t_pswap *pswap, char **log)
{
	t_node	*first;
	t_node	*last;

	if (!pswap || !log)
		return ;
	first = pswap->a->items;
	last = pswap->a->last;
	if (first->value > last->value)
	{
		add_msg_to_log("ra\n", log);
		ra(pswap);
	}
}

static void	move_all_items_from_b_ordered(t_pswap *pswap, char **log)
{
	if (!pswap || !log)
		return ;
	while (pswap->b->size)
	{
		pa(pswap);
		add_msg_to_log("pa\n", log);
		try_swap_a(pswap, log);
	}
}

char	*pswap_sort(t_pswap *pswap)
{
	char	*log;
	size_t	sentinel;
	size_t	size;

	log = NULL;
	if (!pswap || pswap->a->size < 2)
		return (log);
	sentinel = 1;
	size = pswap->a->size;
	while (sentinel <= size)
	{
		try_rotate_up_a(pswap, &log);
		try_swap_a(pswap, &log);
		if (!stack_pos_ordered(pswap->a, sentinel))
		{
			move_n_items_from_a(pswap, sentinel - 1, &log);
			try_rotate_up_a(pswap, &log);
			try_swap_a(pswap, &log);
			move_all_items_from_b_ordered(pswap, &log);
		}
		sentinel++;
	}
	return (log);
}
