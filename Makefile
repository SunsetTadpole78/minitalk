SRC = src
INCLUDE = include ft_printf/include

INCLUDES = $(addprefix -I , $(INCLUDE))

CLIENT = client
SERVER = server

CLIENT_DEFAULT =	client.c \
					utils.c
SERVER_DEFAULT = 	server.c

CLIENT_FILES = $(addprefix $(SRC)/, $(CLIENT_DEFAULT))
SERVER_FILES = $(addprefix $(SRC)/, $(SERVER_DEFAULT))

CLIENT_OBJS = $(CLIENT_FILES:%.c=%.o)
SERVER_OBJS = $(SERVER_FILES:%.c=%.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

FLAGS = -Wall -Wextra -Werror

setup: fclean $(FT_PRINTF) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	cc $(FLAGS) $(CLIENT_OBJS) $(FT_PRINTF) -o $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	cc $(FLAGS) $(SERVER_OBJS) $(FT_PRINTF) -o $(SERVER)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	cc $(FLAGS) $< -c -o $@ $(INCLUDES)

clean:
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make -C $(FT_PRINTF_DIR) fclean

testc:
	cc src/clienttest.c ft_printf/src/*.c -I include -I ft_printf/include -o ct

tests:
	cc src/servertest.c ft_printf/src/*.c -I include -I ft_printf/include -o st
