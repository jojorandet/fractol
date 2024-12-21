NAME = fractol
#directories 
DIR_BIN		=	./bin
DIR_INCLUDE =	./include
DIR_SRC 	=	./src

OBEJCTS		= 	$(addsuffix .o, ($(DIR_SRC) / $(basename $(SRCS))))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitise=address

FT_PRINTF	= ./include/ft_printf
FT_LIBFT	= ./include/libft 

UNAME_S		= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
MINILIBX_PATH	=	./include/minilibx_linux
INCLUDE_FLAGS	=	-I$(FT_PRINTF) -I$(LIBFT) -I$(MINILIBX_PATH)
#allows the compiler to know where to get the header files. 
LIBRARY_PATHS	=	-L$(FT_PRINTF) -I$(LIBFT) -I$(MINILIBX_PATH)
#tels the linker where to find the static libraries .a (libft.a) (pre-compiled code)
LIBRARIES		= -lft -lmx -lX11 -lXext -lm
#-l flags tells the linker which libraries to use during the linking stage
else ifew ($(UNAME_S), Darwin)
MINILIBX_PATH	=	./include/minilibx_macos
INCLUDE_FLAGS	=	-I$(FT_PRINTF) -I$(FT_LIBFT) -I$(MINILIBX_PATH)
LIBRARY_PATHS	=	-L$(FT_PRINTF) -I$(FT_LIBFT) -I$(MINILIBX_PATH)
LIBRARIES		=	-Lmlx -lmlx -framework OpenGL -framework Appkit
endif

all: $(NAME)

$(NAME):	$(OBEJCTS)
	@make -C $(FT_LIBFT)
#build the printf library printf.a
	@make -C $(FT_PRINTF)
	@make -C $(MINILIBX_PATH)
	@cc $(OBJECTS) $(FLAGS) $(LIBRARY_PATHS) $(LIBRARIES) -o $@
#compile everything into the final program.

$(DIR_BIN)/%.o: $(DIR_SRC)/%.c | $(DIR_BIN) 
# the pipe means it depends on the existence of dir bin, if it does not exist then go do the rule below
	@cc $(FLAGS) $(LIBRARIES) -c $^ -o $@
#dollar is all the dependencies / prerequisites, @ represents the target, in this case $(DIR_BIN)/%.o
$(DIR_BIN)
	@mkdir -p @

clean:
	make clean $(FT_PRINTF)
	make clean $(LIBFT)
	rm -rf $(DIR_BIN)

fclean:
	make fclean -C $(FT_PRINTF)
	make fclean -C $(FT_LIBFT)
	rm -rf $(NAME)
#deletes the fractol executable 

re: fclean all
#this cleans everythingm and then it executes all, meaning it builds again

.PHONY = re clean fclean all 