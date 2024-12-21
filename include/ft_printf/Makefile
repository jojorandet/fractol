NAME = libftprintf.a
DIR_SRC = ./
DIR_BUILD = build
FLAGS = -Wall -Wextra -Werror -I ./

SOURCES		=	ft_printf.c \
				ft_putchar.c \
				ft_putnbr_base.c \
				ft_putstr.c \
				ft_pointers.c \
				ft_strlen.c
FUNCTIONS	=	$(subst .c,,$(notdir $(SOURCES)))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -cr $@ $^

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	cc $(FLAGS) -c $^ -o $@

$(DIR_BUILD):
	mkdir $(DIR_BUILD)

so: $(OBJECTS)
	cc -nostartfiles -shared -o libft.so $(NAME_SO) $(OBJECTS)

test: all ./.test.c
	cc $(FLAGS) -L ./ -lftprintf ./.test.c -o test

clean:
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all
