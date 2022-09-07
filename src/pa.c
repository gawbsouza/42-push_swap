/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:47:35 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 16:25:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pswap *pswap)
{
	t_node	*pop;

	if (!pswap || !pswap->b)
		return ;
	pop = stack_pop(pswap->b);
	if (pop)
	{
		if (!pswap->a)
			pswap->a = stack_create();
		stack_push(pswap->a, pop->value);
	}
	free(pop);
}
