# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/05/16 20:51:52 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = \
	src/bmp.c \
	src/calc_light.c \
	src/calc_light2.c \
	src/camera.c \
	src/camera2.c \
	src/color.c \
	src/create_bi.c \
	src/cval.c \
	src/exit.c \
	src/expect.c \
	src/handler1.c \
	src/hittable.c \
	src/init.c \
	src/light.c \
	src/material.c \
	src/minirt.c \
	src/object_aabb.c \
	src/object_cylinder.c \
	src/object_cylinder2.c \
	src/object_plane.c \
	src/object_sphere.c \
	src/object_square.c \
	src/object_triangle.c \
	src/parse.c \
	src/parse_obj.c \
	src/parse_program.c \
	src/parsed.c \
	src/pixel.c \
	src/ray.c \
	src/vector_assignment.c \
	src/vector_etc.c \
	src/vector_op1.c \
	src/vector_op2.c \
	src/vector_random.c \
	src/vector_rotate.c \
	src/parser/abort.c \
	src/parser/converter.c \
	src/parser/expect.c \
	src/parser/file_reader.c \
	src/parser/file_reader2.c \
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
	src/util/bag.c \
	src/util/geo.c \
	src/util/memory.c \
	src/util/mtwister.c \
	src/util/number.c \
	src/util/string.c \

OBJECTS = $(SOURCES:.c=.o)

RM = rm -f
LIBC = ar -rcs
FRAMEWORKS = -framework OpenGL -framework AppKit
INC_DIR = -I./src -I/usr/include -I/usr/local/include
FLAGS = -Wall -Wextra -Werror

# this is for linux
# LIBS = -L/usr/local/lib -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

# this is for mac
# LIBS = -lmlx -framework OpenGL -framework AppKit

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $^ -lmlx $(FRAMEWORKS) -o $@

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)


fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS) $(TM_OBJECTS) $(RM_OBJECTS)


test: $(TEST_OBJECTS)
	$(CC) $(FLAGS) $^ lib/libmlx.a $(FRAMEWORKS) -o do_test
	./do_test

re: fclean all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o
