# Name of the output program
NAME			=	fractol

# Directories for source and build files
DIR_SRC			=	./src
DIR_BUILD		=	./build

# Source and object files
SOURCES			=	exit_function.c image.c keyboard_functions.c main.c mlx_setup.c 
SOURCES_NAME	=	$(basename $(SOURCES))
OBJECTS			=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SOURCES_NAME)))

# Compiler flags
FLAGS			=	-Wall -Wextra -Werror

# Paths to external libraries
FT_PRINTF		=	./lib/ft_printf
LIBX			=	./lib/minilibx-linux
LIBS_INCLUDE	=	-I$(FT_PRINTF) -I$(LIBX)  # Include paths for headers
LIBS_LINK_DIR	=	-L$(FT_PRINTF) -L$(LIBX)  # Link directories
LIBS_LINK		=	-lftprintf -lmlx -lXext -lX11 -lm -lz  # Libraries to link

# Default rule
all: $(NAME)

# Rule to build the final executable
$(NAME): $(OBJECTS)
	@make -C $(FT_PRINTF) # Recursive call to build libftprintf.a
	@cc $(OBJECTS) $(FLAGS) $(LIBS_LINK_DIR) $(LIBS_LINK) -o $@

# Rule to build object files
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) $(LIBS_INCLUDE) -c $^ -o $@

# Rule to create the build directory
$(DIR_BUILD):
	@mkdir -p $@

# Clean rule to remove object files
clean:
	make clean -C $(FT_PRINTF) # Recursive clean for ft_printf
	rm -rf $(DIR_BUILD)

# Fully clean rule to remove the binary and objects
fclean: clean
	make fclean -C $(FT_PRINTF) # Recursive fclean for ft_printf
	rm -f $(NAME)

# Rule to rebuild everything
re: fclean all
	make re -C $(FT_PRINTF) # Recursive re for ft_printf

.PHONY: all clean fclean re
