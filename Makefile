# Name of the output program
NAME			=	fractol

# Directories for source and build files
DIR_SRC			=	./src
DIR_BUILD		=	./build

# Source and object files
SOURCES			=	cleanup.c complex_utils.c draw.c events.c image_utils.c init_data.c init_image.c init_mlx.c main.c view.c 
SOURCES_NAME	=	$(basename $(SOURCES))
OBJECTS			=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SOURCES_NAME)))

# Compiler flags
FLAGS			=	-Wall -Wextra -Werror -g -DGL_SILENCE_DEPRECATION

# Paths to external libraries
FT_PRINTF		=	./lib/ft_printf
LIBFT 			=	./lib/libft
#here I check which OS I am using 
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LIBX			=	./lib/minilibx-linux
	LIBS_INCLUDE 	= 	-I$(FT_PRINTF) -I$(LIBFT) -I$(LIBX) -I/usr/include
	LIBS_LINK_DIR	= 	-L$(FT_PRINTF) -L$(LIBFT) -L$(LIBX) -L/usr/lib
	LIBS_LINK		=	-lftprintf -lft -lmlx -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S), Darwin)
	LIBX			=	./lib/minilibx-macos
	LIBS_INCLUDE 	= 	-I$(FT_PRINTF) -I$(LIBFT) -I$(LIBX)
	LIBS_LINK_DIR	= 	-L$(FT_PRINTF) -L$(LIBFT) -L$(LIBX)
	LIBS_LINK		=	-lftprintf -lft -lmlx -framework OpenGL -framework AppKit
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
	rm -rf $(DIR_BUILD)

# Fully clean rule to remove the binary and objects
fclean: clean
	make fclean -C $(FT_PRINTF) # Recursive fclean for ft_printf
	make fclean -C $(LIBFT)
	rm -f $(NAME)

# Rule to rebuild everything
re: fclean all

.PHONY: all clean fclean re
