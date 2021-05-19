# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/05/19 21:16:13 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = \
	src/array.c \
	src/memory.c \
	src/program.c \
	src/stack.c \
	src/op.c \
	src/parse.c \
	src/resolve.c \
	src/sort.c \
	src/pivot.c \
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
CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS) $(MAINOBJECTS)
	$(CC) $(FLAGS) $^ test.c -o $@

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(MAINOBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)


fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS) $(MAINOBJECTS) test.o


test: $(OBJECTS)
	$(CC) $(FLAGS) $(LIBS) $^ test.c -o do_test

re: fclean all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o
