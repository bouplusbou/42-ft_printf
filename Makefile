OK_COLOR = \033[32m
NO_COLOR = \033[m

OK = $(OK_COLOR)OK$(NO_COLOR)

IDIR = -Iincludes

SRC =  examples.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all

all : 
		@$(CC) $(CFLAGS) examples.c
		@./a.out
