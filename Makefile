# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:47:51 by gasouza           #+#    #+#              #
#    Updated: 2022/09/14 23:19:50 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_D		= ./src
SRCS		+= stack_create.c stack_destroy.c stack_push.c stack_pop.c
SRCS		+= stack_swap.c stack_rotate_up.c stack_rotate_down.c
SRCS		+= pswap_create.c pswap_destroy.c sa.c sb.c ss.c pa.c pb.c
SRCS		+= ra.c rb.c rr.c rra.c rrb.c rrr.c pswap_sort.c
SRCS		+= stack_pos_ordered.c move_n_items_from_a.c add_msg_to_log.c
SRCS		+= stack_is_ordered.c pswap_sort_playback.c has_duplicate_strings.c
SRCS		+= has_only_integers.c

OBJS		= $(addprefix $(SRC_D)/, $(SRCS:.c=.o)) 

INCS		+= -Ilib/libft
LIBS		+= -Llib/libft -lft

LINKER		= gcc
COMPILER	= gcc -c
CFLAGS		= -g -Wall -Werror -Wextra

CLEANUP		= rm -rf

.PHONY: libft
libft:
	@make --no-print-directory -C lib/libft

%.o: %.c libft
	$(COMPILER) $(CFLAGS) $(INCS) $< -o $@

.PHONY: clean
clean:
	$(CLEANUP) $(OBJS)
