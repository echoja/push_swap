# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/05/22 03:03:46 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap checker

SOURCES = \
	src/array.c \
	src/common.c \
	src/check.c \
	src/memory.c \
	src/program.c \
	src/stack.c \
	src/stack_op.c \
	src/op1.c \
	src/op2.c \
	src/op3.c \
	src/parse.c \
	src/resolve_atop1.c \
	src/resolve_atop2.c \
	src/resolve_btop.c \
	src/sort.c \
	src/calc_util.c \
	src/fr_read.c \
	src/parser/abort.c \
	src/parser/converter.c \
	src/parser/expect.c \
	src/parser/file_reader.c \
	src/parser/is.c \
	src/parser/parser.c \
	src/parser/string.c \
	src/parser/string2.c \
	src/parser/string3.c \
	src/parser/tokenizer.c \
	src/parser/tokenizer2.c \
	src/parser/tokenizer_confirm.c \
	src/parser/tokenizer_try.c \
	src/parser/tokenizer_try2.c \
	src/parser/init.c

PUSH_SWAP_MAIN_SRC = src/push_swap.c
CHECKER_MAIN_SRC = src/checker.c

OBJECTS = $(SOURCES:.c=.o)
PUSH_SWAP_MAIN_OBJ = $(PUSH_SWAP_MAIN_SRC:.c=.o)
CHECKER_MAIN_OBJ = $(CHECKER_MAIN_SRC:.c=.o)

RM = rm -rf
INC_DIR = -I./src
FLAGS = -Wall -Wextra -Werror
LIBS = -lm
CC = gcc

all: $(NAME)

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(PUSH_SWAP_MAIN_OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(CHECKER_MAIN_OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

push_swap: $(OBJECTS) $(PUSH_SWAP_MAIN_OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

checker: $(OBJECTS) $(CHECKER_MAIN_OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

$(MAINOBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS) $(PUSH_SWAP_MAIN_OBJ) $(CHECKER_MAIN_OBJ) test.o

test: $(OBJECTS)
	$(CC) $(FLAGS) $^ test.c -o do_test $(LIBS)

re: fclean all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o
