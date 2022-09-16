# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:26:12 by gasouza           #+#    #+#              #
#    Updated: 2022/09/15 22:28:36 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= TestsRunner
RUNNER		= $(BUILD_DIR)/$(NAME)
CC			= gcc
BUILD_DIR	= ./build
CFLAGS		= -g -Wall -Werror -Wextra -DUNITY_FIXTURE_NO_EXTRAS
CLEANUP		= rm -rf

# Tests source code
TEST_SRC	+= ../lib/Unity/extras/fixture/src/unity_fixture.c
TEST_SRC	+= ../lib/Unity/src/unity.c
TEST_SRC	+= $(wildcard *.c)

# Includes
TEST_INC	+= -I../lib/Unity/src
TEST_INC	+= -I../lib/Unity/extras/fixture/src
TEST_INC	+= -I../src
TEST_INC	+= -I../lib/libft

TEST_LIB	+= -L../lib/libft -lft

# Projects objs
PROJ_SRC	= $(filter-out %push_swap.c %checker.c, $(wildcard ../src/*.c)) 
PROJ_OBJ	= $(PROJ_SRC:.c=.o)

# Default ruler
.PHONY: all
all: $(RUNNER) 

$(PROJ_OBJ):
	@make --no-print-directory -C .. $(subst ../, ,$@)

clean_proj:
	@make -C .. clean

# Compile source code
$(RUNNER): clean_proj $(PROJ_OBJ) $(TEST_SRC) $(BUILD_DIR) 
	$(CC) $(CFLAGS) $(TEST_INC) $(PROJ_OBJ) $(TEST_SRC) $(TEST_LIB) -o $(BUILD_DIR)/$(NAME)

# Make 'build' directory
$(BUILD_DIR): 
	mkdir $(BUILD_DIR)

# Run TestsRunner
.PHONY: run
run: all
	@ clear
	@ $(RUNNER)

.PHONY: runv
runv: all
	@ clear
	@ $(RUNNER) -v

.PHONY: rerun
rerun: re run

.PHONY: fclean clean
fclean clean:
	$(CLEANUP) $(BUILD_DIR)

.PHONY: re
re: fclean all
