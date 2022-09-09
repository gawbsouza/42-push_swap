/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:44:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/09 09:38:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pswap	*pswap_create(void)
{
	t_pswap	*ps;

	ps = (t_pswap *) malloc(sizeof(t_pswap));
	if (ps)
	{
		ps->a = stack_create();
		ps->b = stack_create();
		if (!ps->a || !ps->b)
		{
			stack_destroy(&ps->a);
			stack_destroy(&ps->b);
			free(ps);
			ps = NULL;
		}
	}
	return (ps);
}
