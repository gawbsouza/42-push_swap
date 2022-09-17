/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:05:39 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 00:59:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*pswap_sort(t_pswap *pswap)
{
	char	*log;

	if (!pswap || stack_is_ordered(pswap->a))
		return (NULL);
	log = NULL;
	if (pswap->a->size > 10)
		raddix_sort(pswap, &log);
	else
		gabs_sort(pswap, &log);
	return (log);
}
