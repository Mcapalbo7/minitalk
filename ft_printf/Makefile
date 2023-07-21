# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 21:59:22 by mcapalbo          #+#    #+#              #
#    Updated: 2023/03/06 20:58:47 by mcapalbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_hex_putnbr.c ft_putchar.c ft_putstr.c ft_putadress.c ft_unsigned_putnbr.c ft_putnbr.c ft_type.c
OBJ = $(SRC:%.c=%.o)
CC = gcc -c
FLAGS = -Werror -Wall -Wextra

all : $(NAME)
$(NAME) :
	$(CC) $(FLAGS) -I ./ $(SRC)
	ar rcs $(NAME) $(OBJ)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re
