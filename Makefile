#                                  TARGETS                                       #
NAME = fractol

#                                DIRECTOERIES                                    #
DIR_BIN		=	./bin
DIR_INCLUDE =	./include
DIR_SRC 	=	./src
FT_LIBFT	=	./include/libft 
FT_PRINTF   =	./include/ft_printf

#                               COMPILER FLAGS                                  #
CC = gcc
#compilation if linux
CFLAGS = -Wall -Werror -Wextra -g -MMD #MMD generates dependency flags
#MACOS specific 
ifeq ($(UNAME), Darwin)
	CFLAGS += -g -fsanitize=address
endif

#                                SOURCE FILES                                   #
#list of all the source files needed for compialtion
SOURCES		=	color_fractal.c draw_fractal.c events_keys.c events_mouse.c \
				exit_utils.c init_img.c main.c parse.c render.c view.c zoom.c 

#  gemnerate object file names form source files 
SOURCE_NAME	=	$(basename $(SOURCES))
OBJECTS		= 	$(addsuffix .o, $(addprefix $(DIR_BIN)/, $(SOURCE_NAME)))
DEPS		=	$(OBJECTS:.o=.d)	#dependency files for tracking headers

#                              PLATFORM SPECIFIC                                #
# -I look for header files, -L look for library files (.a), -l link with the specific libraries.
UNAME_S		= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
#LINUX specific settings
	MINILIBX_PATH	=	./include/minilibx_linux
	INCLUDE_FLAGS	=	-I$(FT_LIBFT) -I$(MINILIBX_PATH) -I$(DIR_INCLUDE) -I$(FT_PRINTF)
	LIBRARY_PATHS	=	-L$(FT_LIBFT) -L$(MINILIBX_PATH) -L$(FT_PRINTF)
	LIBRARIES		= -lft -lmlx -lftprintf -lX11 -lXext -lm -lz
else ifeq ($(UNAME_S), Darwin)
#MACOS specific settings
	MINILIBX_PATH	=	./include/minilibx_macos
	INCLUDE_FLAGS	=	-I$(FT_LIBFT) -I$(MINILIBX_PATH) -I$(DIR_INCLUDE) -I$(FT_PRINTF)
	LIBRARY_PATHS	=	-L$(FT_LIBFT) -L$(MINILIBX_PATH) -L$(FT_PRINTF)
	LIBRARIES		=	-lft -lmlx -lftprintf -framework OpenGL -framework Appkit
endif

#                                MAIN TARGETS                                  #

all: $(NAME)

$(NAME):	$(OBJECTS)
	@echo "Building $(NAME)"
	@make -C $(FT_LIBFT)
	@make -C $(FT_PRINTF)
	@make -C $(MINILIBX_PATH)
	@$(CC) $(OBJECTS) $(CFLAGS) $(LIBRARY_PATHS) $(LIBRARIES) -o $@
	@echo "$(NAME) built successfully and ready to execute using ./fractol"

$(DIR_BIN)/%.o: $(DIR_SRC)/%.c | $(DIR_BIN)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@
$(DIR_BIN):
	@mkdir -p $@

#                                CLEANING TARGETS                               #

clean:
	@echo "cleaning projects..."
	@make clean -C $(FT_LIBFT)
	@make clean -C $(FT_PRINTF)
	@rm -rf $(DIR_BIN)
	@echo "Clean complete"

fclean: clean
	@echo "Full clean in process..."
	@make fclean -C $(FT_LIBFT)
	@make fclean -C $(FT_PRINTF)
	@rm -rf $(NAME)
	@echo "Full clean complete."

#rebuild everything
re: fclean all

#declare which targets are not files 
.PHONY: re clean fclean all 

-include $(DEPS)