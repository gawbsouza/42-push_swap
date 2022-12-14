/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_sort_playback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:55:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 22:15:56 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_move(t_pswap *pswap, char *move);

void	pswap_sort_playback(t_pswap *pswap, const char *moves)
{
	char	**moves_array;
	size_t	index;

	if (!pswap || !moves)
		return ;
	moves_array = ft_split(moves, '\n');
	if (!moves_array)
		return ;
	index = 0;
	while (moves_array[index])
	{
		execute_move(pswap, moves_array[index]);
		index++;
	}
	index = 0;
	while (moves_array[index])
	{
		free(moves_array[index]);
		index++;
	}
	free(moves_array);
}

static void	execute_move(t_pswap *pswap, char *move)
{
	if (!pswap || !move)
		return ;
	if (is_str_equals("pa", move))
		pa(pswap);
	if (is_str_equals("pb", move))
		pb(pswap);
	if (is_str_equals("sa", move))
		sa(pswap);
	if (is_str_equals("sb", move))
		sb(pswap);
	if (is_str_equals("ss", move))
		ss(pswap);
	if (is_str_equals("ra", move))
		ra(pswap);
	if (is_str_equals("rb", move))
		rb(pswap);
	if (is_str_equals("rr", move))
		rr(pswap);
	if (is_str_equals("rra", move))
		rra(pswap);
	if (is_str_equals("rrb", move))
		rrb(pswap);
	if (is_str_equals("rrr", move))
		rrr(pswap);
}
