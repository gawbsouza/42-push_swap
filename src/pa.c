/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:47:35 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 09:28:52 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pswap *pswap)
{
	if (!pswap)
		return ;
	if (!pswap->b || !pswap->a)
		return ;
	if (pswap->b->size == 0)
		return ;
	stack_push(pswap->a, stack_pop(pswap->b));
}
