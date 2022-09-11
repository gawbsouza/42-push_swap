/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_msg_to_log.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:24:46 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/11 07:30:21 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_msg_to_log(char *msg, char **log)
{
	char	*tmp;

	if (!log || !msg)
		return ;
	if (!*log)
	{
		*log = ft_strdup(msg);
		return ;
	}
	tmp = ft_strjoin(*log, msg);
	if (tmp)
	{
		free(*log);
		*log = tmp;
	}
}
