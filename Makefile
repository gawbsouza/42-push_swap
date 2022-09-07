# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:47:51 by gasouza           #+#    #+#              #
#    Updated: 2022/09/07 13:18:07 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_D		= ./src
SRCS		+= stack_create.c stack_destroy.c stack_push.c stack_pop.c
SRCS		+= stack_swap.c stack_rotate_up.c stack_rotate_down.c
SRCS		+= pswap_create.c pswap_destroy.c sa.c sb.c
OBJS		= $(addprefix $(SRC_D)/, $(SRCS:.c=.o)) 

LINKER		= gcc
COMPILER	= gcc -c
CFLAGS		= -g -Wall -Werror -Wextra

CLEANUP		= rm -rf

%.o: %.c
	$(COMPILER) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	$(CLEANUP) $(OBJS)
