/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:05:39 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 00:57:39 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits_to_shift(t_pswap *pswap);
static void	radix_loop(t_pswap *pswap, int shift, char **log);

void	raddix_sort(t_pswap *pswap, char **log)
{
	int	max_bits;
	int	shift;

	max_bits = max_bits_to_shift(pswap);
	shift = 0;
	while (shift < max_bits)
	{
		radix_loop(pswap, shift, log);
		shift++;
	}
}

static int	max_bits_to_shift(t_pswap *pswap)
{
	int	max_num;
	int	max_bits;

	if (!pswap)
		return (0);
	max_num = pswap->a->size;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	radix_loop(t_pswap *pswap, int shift, char **log)
{
	int	size;
	int	i;

	if (!pswap || !log)
		return ;
	size = pswap->a->size;
	i = 0;
	while (i++ < size)
	{
		if (((pswap->a->items->value >> shift) & 1) == 1)
		{
			ra(pswap);
			add_msg_to_log("ra\n", log);
			continue ;
		}
		pb(pswap);
		add_msg_to_log("pb\n", log);
	}
	while (pswap->b->size)
	{
		pa(pswap);
		add_msg_to_log("pa\n", log);
	}
}
