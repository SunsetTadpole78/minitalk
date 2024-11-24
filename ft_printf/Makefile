SRC = src
INCLUDE = include
DEFAULT = data_initializer.c	\
	  default_formatter.c		\
	  ft_printf.c				\
	  hbase_formatter.c			\
	  len_utils.c				\
	  lib_utils.c				\
	  values_printers.c
FILES = $(addprefix $(SRC)/, $(DEFAULT))
OBJS = $(FILES:%.c=%.o)
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

bonus: $(NAME)

%.o: %.c
	cc $(FLAGS) $< -c -o $@ -I $(INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
