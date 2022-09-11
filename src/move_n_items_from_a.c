/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_n_items_from_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:50:20 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 07:34:29 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_n_items_from_a(t_pswap *pswap, size_t n, char **log)
{
	size_t	items_count;

	if (!pswap || !log || n < 1 || n > pswap->a->size)
		return ;
	items_count = 0;
	while (items_count < n)
	{
		add_msg_to_log("pb\n", log);
		pb(pswap);
		items_count++;
	}
}
