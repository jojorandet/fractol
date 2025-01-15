NAME = fractol
#directories 
DIR_BIN		=	./bin
DIR_INCLUDE =	./include
DIR_SRC 	=	./src

SOURCES		=	main.c init_img.c view.c draw_fractal.c render.c events_mouse.c events_keys.c zoom.c parse.c color_fractal.c 
SOURCE_NAME	=	$(basename $(SOURCES))
OBJECTS		= 	$(addsuffix .o, $(addprefix $(DIR_BIN)/, $(SOURCE_NAME)))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
#CFLAGS = -g -fsanitize=address
#FT_PRINTF	= ./include/ft_printf
FT_LIBFT	= ./include/libft 

UNAME_S		= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
MINILIBX_PATH	=	./include/minilibx_linux
INCLUDE_FLAGS	=	 -I$(FT_LIBFT) -I$(MINILIBX_PATH) -I$(DIR_INCLUDE) #-I$(FT_PRINTF)
#allows the compiler to know where to get the header files. 
LIBRARY_PATHS	=	 -L$(FT_LIBFT) -L$(MINILIBX_PATH) #-L$(FT_PRINTF)
LIBRARIES		= -lft  -lmlx -lX11 -lXext -lm -lz #-lftprintf
else ifeq ($(UNAME_S), Darwin)
MINILIBX_PATH	=	./include/minilibx_macos
INCLUDE_FLAGS	=	-I$(FT_LIBFT) -I$(MINILIBX_PATH) -I$(DIR_INCLUDE) #-I$(FT_PRINTF)
LIBRARY_PATHS	=	-L$(FT_LIBFT) -L$(MINILIBX_PATH) #-L$(FT_PRINTF)
LIBRARIES		=	-lft  -lmlx -framework OpenGL -framework Appkit
endif

all: $(NAME)

$(NAME):	$(OBJECTS)
	@echo "Building $(NAME)"
	@make -C $(FT_LIBFT)
#@make -C $(FT_PRINTF)
	@make -C $(MINILIBX_PATH)
	@$(CC) $(OBJECTS) $(CFLAGS) $(LIBRARY_PATHS) $(LIBRARIES) -o $@
	@echo "$(NAME) built successfully and ready to execute using ./fractol"

$(DIR_BIN)/%.o: $(DIR_SRC)/%.c | $(DIR_BIN)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $^ -o $@
$(DIR_BIN):
	@mkdir -p $@

clean:
	@echo "cleaning projects..."
#@make clean -C $(FT_PRINTF)
	@make clean -C $(FT_LIBFT)
	@rm -rf $(DIR_BIN)
	@echo "Clean complete"

fclean: clean
	@echo "Full clean in process..."
#@make fclean -C $(FT_PRINTF)
	@make fclean -C $(FT_LIBFT)
	@rm -rf $(NAME)
	@echo "Full clean complete."

re: fclean all

.PHONY: re clean fclean all 