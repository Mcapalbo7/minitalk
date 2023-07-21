# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 16:35:16 by mcapalbo          #+#    #+#              #
#    Updated: 2023/07/16 19:45:47 by mcapalbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

SRC1 = client.c
SRC2 = server.c

OBJECTS1 = $(SRC1:.c=.o)
OBJECTS2 = $(SRC2:.c=.o)

NAMEC = client
NAMES = server

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) ${FLAGS} -c $< -o $@

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJECTS1) $(FT_PRINTF)
	$(CC) $(OBJECTS1) $(FT_PRINTF) -o $(NAMEC)

$(NAMES): $(OBJECTS2) $(FT_PRINTF)
	$(CC) $(OBJECTS2) $(FT_PRINTF) -o $(NAMES)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJECTS1) $(OBJECTS2)
	make clean -C $(FT_PRINTF_PATH)

fclean: clean
	$(RM) $(NAMEC) $(NAMES)
	$(RM) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
