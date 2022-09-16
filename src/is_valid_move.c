/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:08:41 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 22:15:42 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_move(char *move)
{
	if (!move)
		return (0);
	if (is_str_equals("pa", move))
		return (1);
	if (is_str_equals("pb", move))
		return (1);
	if (is_str_equals("sa", move))
		return (1);
	if (is_str_equals("sb", move))
		return (1);
	if (is_str_equals("ss", move))
		return (1);
	if (is_str_equals("ra", move))
		return (1);
	if (is_str_equals("rb", move))
		return (1);
	if (is_str_equals("rr", move))
		return (1);
	if (is_str_equals("rra", move))
		return (1);
	if (is_str_equals("rrb", move))
		return (1);
	if (is_str_equals("rrr", move))
		return (1);
	return (0);
}
