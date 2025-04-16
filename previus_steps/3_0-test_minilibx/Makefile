NAME		= onlywindow

CC			= cc

CFLAGS		= -Wall -Wextra -Werror
DPFLAGS		= -MMD -MP
MLXFLAGS	= -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd

SRCS_DIR	= src/
OBJS_DIR	= .obj/
DEP_DIR 	= .dep/
MLX_DIR		= mlx/

MLX_FILE 	= libmlx.a

INCLUDE 	= -I $(MLX_DIR)

SRCS		= 01_test_open_only_window.c

OBJS		= $(SRCS:%.c=%.o)
DEP			= $(OBJS:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(DEP_DIR) $(OBJS)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -lmlx $(MLXFLAGS) $^ -o $@

#	$(CC)-v $(FLAGS) $(LINFLAGS) ./minilibx-linux/libmlx_Linux.a  01_test_open_only_window.c

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Regla para crear el directorio de dependencias
$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile | $(OBJS_DIR) $(DEP_DIR)
	echo "en objetos"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DPFLAGS) $(INCLUDE) -c $< -o $@
	mv $(patsubst %.o,%.d,$@) $(DEP_DIR)/$(notdir $(@:.o=.d)) 

clean:
	@echo "--> Remove Object files"
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean:
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all, clean, fclean, re

