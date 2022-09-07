/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:44:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 11:58:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pswap	*pswap_create(t_stack *a, t_stack *b)
{
	t_pswap	*ps;

	ps = (t_pswap *) malloc(sizeof(t_pswap));
	if (ps)
	{
		ps->a = a;
		ps->b = b;
	}
	return (ps);
}
