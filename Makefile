# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/28 13:15:58 by akorunsk          #+#    #+#              #
#    Updated: 2018/02/21 17:07:51 by akorunsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_DIR = src

SRC = $(shell find $(SRC_DIR) -type f -name "*.c")

INC = -I libft/ -I include/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

LIBNAME = libft/libft.a

all: $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(INC) -o $@ $<

clean: libclean
	rm -rf $(OBJ)

fclean: libfclean clean
	rm -rf $(NAME)

re: fclean all

$(LIBNAME): libmake

libmake:
	@make -C libft/

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean
