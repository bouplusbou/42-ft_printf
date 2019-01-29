# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:34:55 by bclaudio          #+#    #+#              #
#    Updated: 2018/12/07 14:00:27 by bclaudio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## Syntax ##########

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[m

OK = $(GREEN)[OK]$(WHITE)

########## Project Infos ##########

NAME =	a.out
PROJECT = $(RED)Printf$(WHITE)

########## Compilation Infos ##########

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCPATH = includes/
INC = -I$(INCPATH) -I$(LIBPATH)$(INCPATH)			

LIBPATH = libft/
LIBNAME = libft.a
LIB = $(LIBPATH)$(LIBNAME)

########## Sources ##########

SRCPATH = src/
SRCS = $(addprefix $(SRCPATH), $(SRC))
SRC = checks.c \
      ft_printf.c \
      parse_conv.c \
      printf_write.c \
      treat_conv.c \
      treat_format.c \
      convert.c \
      conv_char.c \
      conv_ptr.c \
      main.c

########## Compilation Rules ##########

OBJ = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $?

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBPATH) fclean && make -C $(LIBPATH)
	@$(CC) $(FLAGS) $(INC) $(OBJ) $(LIB) -o $(NAME)
	@echo "$(BLUE)[$(PROJECT)$(BLUE)] | Compilation$(WHITE)						$(OK)"

test : all
	@./$(NAME)

re : fclean all

########## Clean Rules ##########

clean :
	@rm -f $(OBJ)
	@echo "$(BLUE)[$(PROJECT)$(BLUE)] | Clean$(WHITE)						$(OK)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(BLUE)[$(PROJECT)$(BLUE)] | Full clean$(WHITE)						$(OK)"
