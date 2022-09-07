/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:12:32 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/07 17:14:59 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_pswap *pswap)
{
	if (!pswap || !pswap->b)
		return ;
	stack_rotate_up(pswap->b);
}
