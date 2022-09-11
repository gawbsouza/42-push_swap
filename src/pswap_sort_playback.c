/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_sort_playback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:55:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 13:53:48 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_move(t_pswap *pswap, char *move);
static int	str_equals(const char *s1, const char *s2);

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
}

static void	execute_move(t_pswap *pswap, char *move)
{
	if (!pswap || !move)
		return ;
	if (str_equals("pa", move))
		pa(pswap);
	if (str_equals("pb", move))
		pb(pswap);
	if (str_equals("sa", move))
		sa(pswap);
	if (str_equals("sb", move))
		sb(pswap);
	if (str_equals("ss", move))
		ss(pswap);
	if (str_equals("ra", move))
		ra(pswap);
	if (str_equals("rb", move))
		rb(pswap);
	if (str_equals("rr", move))
		rr(pswap);
	if (str_equals("rra", move))
		rra(pswap);
	if (str_equals("rrb", move))
		rrb(pswap);
	if (str_equals("rrr", move))
		rrr(pswap);
}

static int	str_equals(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, ft_strlen(s2) + 1) == 0);
}
