# Executable Name
NAME = test

# Compiler and FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# Linux Include and default libs for MLX
MLXFLAGS = -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd

# Paths
MLX_DIR = lib/mlx/
SRCS_DIR = src/
OBJS_DIR = .objs/
DEP_DIR = .dep/

# Source files
SRC_FILES = 01_test_open_only_window.c

# Objet files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Dependency files
DEPS_FILES = $(SRC_FILES:.o=.d)

# 
# Rutas completas de las bibliotecas
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS = $(addprefix $(DEP_DIR), $(DEPS_FILES))

# Include Paths
INCLUDE = -I include/ -I $(MLX_DIR)

# Delete folders and files
RM = rm -rf

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

# Default rule
all: $(NAME)

# Libs compile rule
subsystems:
	@echo "$(CYAN)▉▉▉▉▉▉▶ START: Compiling extenal libs ...$(RESET)"
	@echo "$(YELLOW)▶ Compiling MinilibX...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(CYAN)▉▉▉▉▉▉▶ END: Extenal libs compiled ...$(RESET)"
	@echo

# Executable Rule
$(NAME): subsystems $(OBJS_DIR) $(DEP_DIR) $(OBJS) 
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ Compiling : $(NAME) ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $@
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ $(NAME) successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo

# Objects folder rule
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Dependencies folder rule
$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

# Source files to Object files rule (Dependency files are generated)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(Makefile) | $(OBJS_DIR) $(DEP_DIR)
	@echo "$(CYAN)▉▉▉▉▉▉▶ START: Creating objects and depenencies files...$(RESET)"
	@mkdir -p $(dir $@)
	@echo "▶ Compiling... $<"
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDE)
	@mv $(patsubst %.o,%.d,$@) $(DEP_DIR)/$(notdir $(@:.o=.d))
	@echo "$(CYAN)▉▉▉▉▉▉▶ END: Objects and depenencies created...$(RESET)"
	@echo

# Delete objects and dependecies folders
clean:
	@echo "$(YELLOW)▶ Cleaning object files and dependencies...$(RESET)"
	$(RM) $(OBJS_DIR) $(DEP_DIR)

# Delete executable, objects and dependecies folders
fclean: clean
	@echo "$(YELLOW)▶ Cleaning executable...$(RESET)"
	$(RM) $(NAME)

# Regla para reconstruir todo
re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re subsystems
