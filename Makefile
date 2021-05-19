# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/05/20 03:03:28 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = \
	src/array.c \
	src/memory.c \
	src/program.c \
	src/stack.c \
	src/op1.c \
	src/op2.c \
	src/op3.c \
	src/parse.c \
	src/resolve_atop.c \
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


MAIN = src/main.c

OBJECTS = $(SOURCES:.c=.o)
MAINOBJECTS = $(MAIN:.c=.o)
RM = rm -rf
INC_DIR = -I./src
FLAGS = -Wall -Wextra -Werror -g
LIBS = -lm
CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS) $(MAINOBJECTS)
	$(CC) $(FLAGS) $^ test.c -o $@ $(LIBS)

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(MAINOBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)


fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS) $(MAINOBJECTS) test.o


test: $(OBJECTS)
	$(CC) $(FLAGS) $^ test.c -o do_test $(LIBS)

re: fclean all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o
