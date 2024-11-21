FT_PRINTF_SRC = ft_printf/src
SRC = src
INCLUDE = include ft_printf/include

INCLUDES = $(addprefix -I , $(INCLUDE))

FT_PRINTF = libftprintf.a
CLIENT = client
SERVER = server

FT_PRINTF_DEFAULT =	data_initializer.c	\
	  		default_formatter.c	\
			ft_printf.c		\
			hbase_formatter.c	\
			len_utils.c		\
			lib_utils.c		\
			values_printers.c
CLIENT_DEFAULT =	client.c
SERVER_DEFAULT = 	server.c

FT_PRINTF_FILES = $(addprefix $(FT_PRINTF_SRC)/, $(FT_PRINTF_DEFAULT))
CLIENT_FILES = $(addprefix $(SRC)/, $(CLIENT_DEFAULT))
SERVER_FILES = $(addprefix $(SRC)/, $(SERVER_DEFAULT))

FT_PRINTF_OBJS = $(FT_PRINTF_FILES:%.c=%.o)
CLIENT_OBJS = $(CLIENT_FILES:%.c=%.o)
SERVER_OBJS = $(SERVER_FILES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

setup: fclean $(FT_PRINTF) $(CLIENT) $(SERVER)

$(FT_PRINTF): $(FT_PRINTF_OBJS)
	ar cr $(FT_PRINTF) $(FT_PRINTF_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	cc $(FLAGS) $(CLIENT_OBJS) $(FT_PRINTF) -o $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	cc $(FLAGS) $(SERVER_OBJS) $(FT_PRINTF) -o $(SERVER)

%.o: %.c
	cc $(FLAGS) $< -c -o $@ $(INCLUDES)

clean:
	rm -f $(FT_PRINTF_OBJS)
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)

fclean: clean
	rm -f $(FT_PRINTF)
	rm -f $(CLIENT)
	rm -f $(SERVER)
