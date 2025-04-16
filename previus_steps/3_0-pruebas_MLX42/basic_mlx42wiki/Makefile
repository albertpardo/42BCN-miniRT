# 240714 This file has been modified from original

CC		:= cc

NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ../MLX42

LIBMLXA := $(LIBMLX)/build/libmlx42.a
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lpthread -lm
#SRCS	:= $(shell find ./src -iname "*.c")
SRCS	:= src/main.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c  Makefile
	@echo
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@echo
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)
#	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
