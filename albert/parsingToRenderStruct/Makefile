# Executable Name
NAME = miniRT_parsingToRender

# Makefile path and name
MAKEFILE = ./Makefile

# Compiler and FLAGS
CC = cc
CFLAGS = #-Wall -Wextra -Werror -g3 #-fsanitize=address
DPFLAGS = -MMD -MP

# Linux Include and default libs for MLX
MLX_LINUX_FLAGS = -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd
MLX_LIB_FLAGS = -L$(MLX_DIR) -lmlx
MLXFLAGS = $(MLX_LINUX_FLAGS) $(MLX_LIB_FLAGS)

# Paths
MLX_DIR = lib/mlx/
LIBFT_DIR = lib/libft/
SRCS_DIR = src/
OBJS_DIR = .objs/
DEP_DIR = .dep/

CONFIGURE := $(MLX_DIR)configure

# Include Paths
# INCLUDE := -I include/ -I $(LIBFT_DIR)

#Libft flags
LIBFTFLAGS := -L $(LIBFT_DIR) -lft

INCLUDE = -I include/ -I $(MLX_DIR) -I $(LIBFT_DIR)

#Libft.a
LIBFT := $(LIBFT_DIR)libft.a

# Source files
SRC_FILES_PARSING = minirt_main_pars_to_render.c \
	rendering.c \
	parsing/cleanstringspaces.c \
	parsing/clearscene.c \
	parsing/countchar.c \
	parsing/exiterror.c \
	parsing/exiterrorfreemsg.c \
	parsing/exitifcheckfails.c \
	parsing/exitifnotvalidfiletype.c \
	parsing/freearrstr.c \
	parsing/freecleanlineandgetnl.c \
	parsing/freelinscenfdexitbymalloc.c \
	parsing/freescnparsfdexitmsg.c \
	parsing/ft_astrlen.c \
	parsing/ft_isspace.c \
	parsing/ft_isstralpha.c \
	parsing/ft_strichr.c \
	parsing/iselement.c \
	parsing/isokambient.c \
	parsing/isokcamara.c \
	parsing/isokcylin.c \
	parsing/isoklight.c \
	parsing/isokplan.c \
	parsing/isokspher.c \
	parsing/iscoordinatestr.c \
	parsing/isfov.c \
	parsing/isorientnormal.c \
	parsing/isrgbstr.c \
	parsing/isstrfloatcerone.c \
	parsing/isstrfloatsgnone.c \
	parsing/isstringvalueinpositiverange.c \
	parsing/isstrsgnfloat.c \
	parsing/setambient.c \
	parsing/setcamara.c \
	parsing/setcylinder.c \
	parsing/setelementinscene.c \
	parsing/setlight.c \
	parsing/setnormalrgb.c \
	parsing/setplane.c \
	parsing/setsceneorexit.c \
	parsing/setsphere.c \
	parsing/setvectorinelemtscene.c \
	parse_to_render/setsceneglobal.c \
	tests/aux/putarraystr.c \
	tests/aux/putsceneinfoinline.c \
	tests/aux/putsceneinfo.c

SRC_FILES_RENDER = clamp/clamp.c lighting/lighting.c moller_tumbore/algorithm.c \
		quaternion_operations/quat_operations.c ray/ray.c render/render.c \
		render/screen.c shapes/cylinder/cylinder.c shapes/plane/plane.c \
		shapes/sphere/sphere.c vector_operations/operations.c \
		vector_operations/operations_two.c vector_operations/operations_three.c \
		shapes/translate.c moller_tumbore/algorithm_aux.c shapes/sphere/sphere_aux.c \
		quaternion_operations/rotate.c lighting/ambient.c

SRC_FILES = $(SRC_FILES_PARSING) $(SRC_FILES_RENDER)

HEADER_FILES = include/parsing.h \
	include/testaux.h

# Objet files
OBJ_FILES := $(SRC_FILES:.c=.o)

# Dependency files
DEPS_FILES := $(SRC_FILES:.o=.d)

# Path to .o and .d 
OBJS := $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS := $(addprefix $(DEP_DIR), $(DEPS_FILES))

# Delete folders and files
RM = rm -rf

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

# Default rule
all: compilelibs
	@echo "\n$(GREEN)▉▉▉▉▉▉▉▉▉▉ $(NAME) ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@$(MAKE) -f $(MAKEFILE) $(NAME) --no-print-directory
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ $(NAME) successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo

# Libs compile rule
compilelibs: 
	@echo "$(CYAN)▉▉▉▉▉▉▶ START: Compiling external libs ...$(RESET)"
	@echo "$(YELLOW)▶ Compiling Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(YELLOW)▶ Compiling MinilibX...$(RESET)"
	@if ! [ -x $(CONFIGURE) ] ; then chmod 744 $(CONFIGURE); fi
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@echo "$(CYAN)▉▉▉▉▉▉▶ END: Extenal libs compiled ...$(RESET)"
	@echo

# Executable Rule
$(NAME): $(OBJS_DIR) $(DEP_DIR) $(OBJS) 
	@echo "\n$(YELLOW)▶ Compiling $(NAME) ... $(RESET)"
	@$(CC) $(CFLAGS) $(DPFLAGS) $(INCLUDE) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) -o $@

# Objects folder rule
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Dependencies folder rule
$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

# Source files to Object files rule (Dependency files are generated)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(MAKEFILE) $(LIBFT) $(HEADER_FILES) | $(OBJS_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@)
	@echo "▶ Compiling... $<"
	@$(CC) $(CFLAGS) $(DPFLAGS) $(INCLUDE) -O3 -c $< -o $@ 
	@mv $(patsubst %.o,%.d,$@) $(DEP_DIR)/$(notdir $(@:.o=.d))

# Delete objects and dependecies folders, and 'fclean' libreries
clean:
	@echo "$(YELLOW)▶ Cleaning object files and dependencies...$(RESET)"
	$(RM) $(OBJS_DIR) $(DEP_DIR)
	@echo "$(YELLOW)▶ Cleaning libft$(RESET)"
	make -C lib/libft/ fclean
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
