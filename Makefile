OK_COLOR = \033[32m
NO_COLOR = \033[m

OK = $(OK_COLOR)OK$(NO_COLOR)

NAME = libftprintf.a

SDIR = ./src
IDIR = ./includes

SRC = 	ft_printf.c \
		treat_format.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "libftprintf.a creation		OK"

%.o: %.c
	$(CC) $(CFLAGS) -I$(IDIR) -o $@ -c $?

clean :
	/bin/rm -f $(OBJ)
	@echo "clean		OK"

fclean : clean
	/bin/rm -f $(NAME)
	@echo "fclean		OK"

re : fclean all	