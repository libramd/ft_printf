# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 15:52:10 by mdiakhat          #+#    #+#              #
#    Updated: 2021/07/02 13:52:20 by mdiakhat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

AR = ar

ARFLAGS = rc

CFlAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = 	ft_printf.c\
		conv_c.c\
		conv_d.c\
		conv_p.c\
		conv_s.c\
		conv_u.c\
		conv_x.c\
		conv_xup.c\
		ft_printf_utils.c\
		ft_printf_utils2.c\
		ft_printf_utils3.c\
		ft_printf_utils4.c\
		ft_printf_utils5.c\
		ft_printf_utils6.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

