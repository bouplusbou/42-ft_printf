# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboucher <bboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/27 16:07:51 by bboucher          #+#    #+#              #
#    Updated: 2019/01/27 16:13:04 by bboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OK_COLOR = \033[32m
NO_COLOR = \033[m

OK = $(OK_COLOR)OK$(NO_COLOR)

NAME = libftprintf.a

SDIR = ./src
IDIR = ./includes

SRC = 	ft_printf.c \
		treat_format.c \
		printf_write.c \
		ft_strlen.c \
		checks.c \
		treat_conv.c \
		ft_strndup.c \
		parse_conv.c \
		ft_atoi.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "libftprintf.a creation		OK"

%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -I$(IDIR) -o $@ -c $?

test : re
	$(CC) $(CFLAGS) main.c -o test -I$(IDIR) libftprintf.a
	@echo "libftprintf.a creation		OK"
	./test

clean :
	/bin/rm -f $(OBJ)
	@echo "clean		OK"

fclean : clean
	/bin/rm -f $(NAME)
	@echo "fclean		OK"

re : fclean all
