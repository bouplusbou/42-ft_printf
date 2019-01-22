OK_COLOR = \033[32m
NO_COLOR = \033[m

OK = $(OK_COLOR)OK$(NO_COLOR)

IDIR = -Iincludes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all

all : 
		@$(CC) $(CFLAGS) get_arg.c
		@./a.out
