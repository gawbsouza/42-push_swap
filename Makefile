# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:47:51 by gasouza           #+#    #+#              #
#    Updated: 2022/09/06 21:46:43 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_D		= ./src
SRCS		+= stack_create.c stack_destroy.c stack_push.c stack_pop.c
SRCS		+= stack_swap.c
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
