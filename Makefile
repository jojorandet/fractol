# Name of the output program
NAME			=	fractol

# Directories for source and build files
DIR_SRC			=	./src
DIR_BUILD		=	./build

# Source and object files
SOURCES			=	calculations.c colours.c exit_function.c image.c julia.c keyboard_functions.c main.c mlx_setup.c 
SOURCES_NAME	=	$(basename $(SOURCES))
OBJECTS			=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SOURCES_NAME)))

# Compiler flags
FLAGS			=	-Wall -Wextra -Werror -g

# Paths to external libraries
FT_PRINTF		=	./lib/ft_printf
LIBFT 			=	./lib/libft
LIBX			=	./lib/minilibx-linux
LIBS_INCLUDE	=	-I$(FT_PRINTF) -I$(LIBFT) -I$(LIBX)  # Include paths for headers
LIBS_LINK_DIR	=	-L$(FT_PRINTF) -L$(LIBFT) -L$(LIBX)  # Link directories
LIBS_LINK		=	-lftprintf -lft -lmlx -lXext -lX11 -lm -lz  # Libraries to link

# Default rule
all: $(NAME)

# Rule to build the final executable
$(NAME): $(OBJECTS)
	@make -C $(FT_PRINTF) # Recursive call to build libftprintf.a
	@make -C $(LIBFT) # Recursive call to build libftprintf.a
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
	rm -rf $(DIR_BUILD)

# Fully clean rule to remove the binary and objects
fclean: clean
	make fclean -C $(FT_PRINTF) # Recursive fclean for ft_printf
	make fclean -C $(LIBFT)
	rm -f $(NAME)

# Rule to rebuild everything
re: fclean all
	make re -C $(FT_PRINTF) # Recursive re for ft_printf
	make re -C $(LIBFT)

.PHONY: all clean fclean re
