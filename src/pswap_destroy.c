/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:09:46 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 12:34:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pswap_destroy(t_pswap **pswap)
{
	if (!pswap || !*pswap)
		return ;
	stack_destroy(&(*pswap)->a);
	stack_destroy(&(*pswap)->b);
	free((*pswap));
	(*pswap) = NULL;
}
