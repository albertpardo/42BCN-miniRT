NAME  	= window	
CC		= cc

CFLAGS 	= -Wall -Wextra -Werror
LIBMLX 	= ../../MLX42 

HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS 	= 01_test_open_only_window.c 
OBJS 	= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
