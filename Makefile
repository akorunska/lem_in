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

INC = -I libft/ -I ft_printf/ -I include/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

LIBNAME = libft/libft.a

FTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(FTPRINTF) $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(INC) -o $@ $<

clean: libclean ftprintfclean
	rm -rf $(OBJ)

fclean: libfclean clean ftprintffclean
	rm -rf $(NAME)

re: fclean all

$(LIBNAME): libmake

libmake:
	@make -C libft/

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean

$(FTPRINTF): ftprintfmake

ftprintfmake:
	@make -C ft_printf/

ftprintfclean:
	@make -C ft_printf/

ftprintffclean:
	@make -C ft_printf/
