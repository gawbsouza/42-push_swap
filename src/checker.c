/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:25:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/09/17 13:06:21 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	read_play_log(char **play_log);
static void	exit_error(void);

int	main(int argc, char **argv)
{
	t_pswap	*pswap;
	char	*play_log;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!is_valid_args(--argc, ++argv))
		exit_error();
	play_log = NULL;
	if (!read_play_log(&play_log))
	{
		free(play_log);
		exit_error();
	}
	pswap = pswap_create();
	while (argc--)
		stack_push(pswap->a, ft_atoi(argv[argc]));
	pswap_sort_playback(pswap, play_log);
	if (stack_is_ordered(pswap->a) && pswap->b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	pswap_destroy(&pswap);
	free(play_log);
	exit(EXIT_SUCCESS);
}

static int	read_play_log(char **play_log)
{
	char	*line;
	char	*move;

	line = get_next_line(0);
	while (line)
	{
		move = ft_strtrim(line, "\n");
		if (!is_valid_move(move))
		{
			free(move);
			free(line);
			return (0);
		}
		add_msg_to_log(line, play_log);
		free(move);
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static void	exit_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}
