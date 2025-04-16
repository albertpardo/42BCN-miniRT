# Executable Name
NAME = test_miniRT

# Makefile path and name
MAKEFILE = Makefile 

# Compiler and FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address #g
DPFLAGS = -MMD -MP
MATHFLAG = -O3

# Linux Include and default libs for MLX
MLX_LINUX_FLAGS = -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd
MLX_LIB_FLAGS = -L$(MLX_DIR) -lmlx
MLXFLAGS = $(MLX_LINUX_FLAGS) $(MLX_LIB_FLAGS)

# Paths
MLX_DIR = lib/mlx/
SRCS_DIR = src/
OBJS_DIR = .objs/
DEP_DIR = .dep/

CONFIGURE := $(MLX_DIR)configure

# Include Paths
INCLUDE = -I include/ -I $(MLX_DIR)

# Source files
SRC_FILES = main.c

# Objet files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Dependency files
DEPS_FILES = $(SRC_FILES:.o=.d)

# Complete Path to Object and Dependencies
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS = $(addprefix $(DEP_DIR), $(DEPS_FILES))

# Delete folders and files
RM = rm -rf

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

# Default rule
all: compilelibs
	@$(MAKE) -f $(MAKEFILE) $(NAME) --no-print-directory

# Libs compile rule
compilelibs:
	@echo "$(CYAN)▉▉▉▉▉▉▶ START: Compiling extenal libs ...$(RESET)"
	@echo "$(YELLOW)▶ Compiling MinilibX...$(RESET)"
	@if ! [ -x $(CONFIGURE) ] ; then chmod 744 $(CONFIGURE); fi
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@echo "$(CYAN)▉▉▉▉▉▉▶ END: Extenal libs compiled ...$(RESET)"
	@echo

# Executable Rule
$(NAME): $(OBJS_DIR) $(DEP_DIR) $(OBJS) 
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ $(NAME) ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo "▶ Compiling $(NAME) ... "
	@$(CC) $(OBJS) $(MLXFLAGS) -o $@
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ $(NAME) successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo

#	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $@
#	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ $(NAME) successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
#	@echo

# Objects folder rule
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Dependencies folder rule
$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

# Source files to Object files rule (Dependency files are generated)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(MAKEFILE) $(HEADER_FILES) | $(OBJS_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@)
	@echo "▶ Compiling... $<"
	@$(CC) $(DPFLAGS) $(INCLUDE) $(MATHFLAG) -c $< -o $@ 
	@mv $(patsubst %.o,%.d,$@) $(DEP_DIR)/$(notdir $(@:.o=.d))
	@echo

#	@$(CC) $(CFLAGS) $(DPFLAGS) $(INCLUDE) $(MATHFLAG) -c $< -o $@ 
#	@mv $(patsubst %.o,%.d,$@) $(DEP_DIR)/$(notdir $(@:.o=.d))
#	@echo

# Delete objects and dependecies folders
clean:
	@echo "$(YELLOW)▶ Cleaning object files and dependencies...$(RESET)"
	$(RM) $(OBJS_DIR) $(DEP_DIR)
	@echo "$(YELLOW)▶ Cleaning MLX lib$(RESET)"
	make -C lib/mlx/ clean

# Delete executable, objects and dependecies folders
fclean: clean
	@echo "$(YELLOW)▶ Cleaning executable...$(RESET)"
	$(RM) $(NAME)

# Regla para reconstruir todo
re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re compilelibs
