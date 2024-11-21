SRC = src
CLIENT = client
SERVER = server

CLIENT_FILES = $(SRC)/$(CLIENT).c
SERVER_FILES = $(SRC)/$(SERVER).c

CLIENT_OBJS = $(CLIENT_FILES:%.c=%.o)
SERVER_OBJS = $(SERVER_FILES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(CLIENT): $(CLIENT_OBJS)
	cc $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	cc $(FLAGS) $(SERVER_OBJS) -o $(SERVER)

%.o: %.c
	cc $(FLAGS) $< -c -o $@

clean:
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
