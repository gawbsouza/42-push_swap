/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:10:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/15 22:11:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_str_equals(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, ft_strlen(s2) + 1) == 0);
}
