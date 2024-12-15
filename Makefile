# Name of the output program
NAME			=	fractol

# Directories for source and build files
DIR_SRC			=	./src
DIR_BUILD		=	./build

# Source and object files
SOURCES			=	calculations.c colours.c drawing.c exit_function.c image.c julia.c keyboard_functions.c main.c mlx_setup.c mouse_functions.c 
SOURCES_NAME	=	$(basename $(SOURCES))
OBJECTS			=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SOURCES_NAME)))

# Compiler flags
FLAGS			=	-Wall -Wextra -Werror -g

# Paths to external libraries
FT_PRINTF		=	./lib/ft_printf
LIBFT 			=	./lib/libft
LIBX_LINUX		=	./lib/minilibx-linux
LIBX_MACOS		= 	./lib/minilibx-macos

LIBS_INCLUDE_LINUX	=	-I$(FT_PRINTF) -I$(LIBFT) -I$(LIBX_LINUX)  # Include paths for headers on linux
LIBS_INCLUDE_MACOS	=	-I$(FT_PRINTF) -I$(LIBFT) -I$(LIBX_MACOS)

LIBS_LINK_DIR_LINUX	=	-L$(FT_PRINTF) -L$(LIBFT) -L$(LIBX_LINUX)  # Link directories
LIBS_LINK_LINUX		=	-lftprintf -lft -lmlx -lXext -lX11 -lm -lz  # Libraries to link

LIBS_LINK_DIR_MACOS	=	-L$(FT_PRINTF) -L$(LIBFT) -L$(LIBX_MACOS)  # Link directories
LIBS_LINK_MACOS		=	-lftprintf -lft -lmlx -framework OpenGL -framework AppKit   # Libraries to link
# Default rule

#here I check which OS I am using 
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LIBS_INCLUDE 	= 	$(LIBS_INCLUDE_LINUX)
	LIBS_LINK_DIR	= 	$(LIBS_LINK_DIR_LINUX)
	LIBS_LINK		=	$(LIBS_LINK_LINUX)
	LIBX			=	$(LIBX_LINUX)
else ifeq ($(UNAME_S), Darwin)
	LIBS_INCLUDE 	= 	$(LIBS_INCLUDE_MACOS)
	LIBS_LINK_DIR	= 	$(LIBS_LINK_DIR_MACOS)
	LIBS_LINK		=	$(LIBS_LINK_MACOS)
	LIBX			=	$(LIBX_MACOS)
endif

all: $(NAME)	

# Rule to build the final executable
$(NAME): $(OBJECTS)
	@make -C $(FT_PRINTF) # Recursive call to build libftprintf.a
	@make -C $(LIBFT) # Recursive call to build libftprintf.a
	@make -C $(LIBX) 
	@cc $(OBJECTS) $(FLAGS) $(LIBS_LINK_DIR) $(LIBS_LINK) -o $@

# Rule to build object files
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) $(LIBS_INCLUDE) -c $^ -o $@

# Rule to create the build directory
$(DIR_BUILD):
	@mkdir -p $@ 
#the -p makes the parent directories automatically

# Clean rule to remove object files
clean:
	make clean -C $(FT_PRINTF) # Recursive clean for ft_printf
	make clean -C $(LIBFT)
	make clean -C $(LIBX)
	rm -rf $(DIR_BUILD)

# Fully clean rule to remove the binary and objects
fclean: clean
	make fclean -C $(FT_PRINTF) # Recursive fclean for ft_printf
	make fclean -C $(LIBFT)
	make fclean -C $(LIBX)
	rm -f $(NAME)

# Rule to rebuild everything
re: fclean all

.PHONY: all clean fclean re
