# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bclaudio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:34:55 by bclaudio          #+#    #+#              #
#    Updated: 2019/01/31 14:09:09 by bclaudio         ###   ########.fr        #
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

########## Lib Infos ##########

NAME = libftprintf.a
PROJECT = $(RED)LibftPrintf$(WHITE)

########## Executable Infos ##########

EXNAME = Printf

########## Compilation Infos ##########

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCPATH = includes/
INC = -I$(INCPATH)

########## Sources ##########

SRCS = $(addprefix $(SRCPATH), $(SRC)) $(addprefix $(LIBSRCPATH), $(LIBSRC))

	##### Printf Sources #####
SRCPATH = src/
SRC = checks.c \
      ft_printf.c \
      parse_conv.c \
      printf_write.c \
      treat_conv.c \
      treat_format.c \
      convert.c \
	  conv_id.c \
	  conv_p.c \
	  conv_oux.c \
	  delete_struct.c \
	  conv_cs.c

	##### Libft Sources #####
LIBSRCPATH = libsrc/
LIBSRC = ft_strlen.c \
	  ft_strcpy.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_atoi.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strdup.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strlcat.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_charequ.c \
	  ft_min.c \
	  ft_max.c \
	  ft_swap.c \
	  ft_realloc.c \
	  ft_strctrim.c \
	  ft_strjoinf.c \
	  get_next_line.c \
	  ft_strndup.c \
	  ft_itoa_base.c \
	  ft_ultoa_base.c \
	  ft_lltoa_base.c \
	  ft_ulltoa_base.c \
	  ft_get_char_index.c

	##### EXEC SOURCE #####
EXSRCS = $(addprefix $(EXPATH), $(EXSRC))
EXPATH = tests/
EXSRC = main.c \

########## Compilation Rules ##########

OBJ = $(SRCS:.c=.o)
EXOBJ = main.o \

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $?

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BLUE)[$(PROJECT)$(BLUE)] | Compilation$(WHITE)						$(OK)"

ex : all
	@$(CC) -c $(INC) $(EXSRCS) 
	@$(CC) $(INC) $(EXOBJ) $(NAME) -o $(EXNAME)
	@echo "$(BLUE)[$(RED)$(EXNAME)$(BLUE)] | Compilation$(WHITE)							$(OK)"
	
testc : ex
	@./$(EXNAME) c

testo : ex
	@./$(EXNAME) o

re : fclean all

########## Clean Rules ##########

clean :
	@rm -f $(OBJ) $(EXOBJ)
	@echo "$(BLUE)[$(PROJECT)$(BLUE) && $(RED)$(EXNAME)$(BLUE)] | Clean$(WHITE)						$(OK)"

fclean : clean
	@rm -f $(NAME) $(EXNAME)
	@echo "$(BLUE)[$(PROJECT)$(BLUE) && $(RED)$(EXNAME)$(BLUE)] | Full clean$(WHITE)					$(OK)"
