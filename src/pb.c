/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:47:35 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 16:54:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_pswap *pswap)
{
	t_node	*pop;

	if (!pswap || !pswap->a)
		return ;
	pop = stack_pop(pswap->a);
	if (pop)
	{
		if (!pswap->b)
			pswap->b = stack_create();
		stack_push(pswap->b, pop->value);
	}
	free(pop);
}
