# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:47:51 by gasouza           #+#    #+#              #
#    Updated: 2022/09/15 11:23:13 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS		+= stack_create.c stack_destroy.c stack_push.c stack_pop.c
SRCS		+= stack_swap.c stack_rotate_up.c stack_rotate_down.c
SRCS		+= pswap_create.c pswap_destroy.c sa.c sb.c ss.c pa.c pb.c
SRCS		+= ra.c rb.c rr.c rra.c rrb.c rrr.c pswap_sort.c
SRCS		+= stack_pos_ordered.c move_n_items_from_a.c add_msg_to_log.c
SRCS		+= stack_is_ordered.c pswap_sort_playback.c has_duplicate_strings.c
SRCS		+= has_only_integers.c push_swap.c

SRC_D		= ./src
OBJS		= $(addprefix $(SRC_D)/, $(SRCS:.c=.o)) 

LIBFT_D		= lib/libft
LIBFT_I		= -I$(LIBFT_D)
LIBFT_L		= -L$(LIBFT_D) -lft
LIBFT_A		= $(LIBFT_D)/libft.a

LINKER		= gcc
COMPILER	= gcc -c
CFLAGS		= -g -Wall -Werror -Wextra

CLEANUP		= rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@printf "compiling push_swap ... \t\t"
	@$(LINKER) $(CFLAGS) $^ $(LIBFT_L) -o $@
	@echo OK!

$(LIBFT_A):
	@printf "compiling libft ... \t\t\t"
	@make -s -C $(LIBFT_D)
	@echo OK!

%.o: %.c $(LIBFT_A)
	@$(COMPILER) $(CFLAGS) $(LIBFT_I) $< -o $@

.PHONY: clean
clean:
	@printf "cleaning push_swap objects ... \t\t"
	@$(CLEANUP) $(OBJS)
	@echo OK!
	@printf "cleaning libft objects ... \t\t"
	@make -s -C $(LIBFT_D) clean
	@echo OK!

.PHONY: fclean
fclean: clean
	@printf "cleaning push_swap executable ... \t"
	@$(CLEANUP) $(NAME)
	@echo OK!
	@printf "cleaning libft static library ... \t"
	@make -s -C $(LIBFT_D) fclean
	@echo OK!

.PHONY: re
re: fclean all
