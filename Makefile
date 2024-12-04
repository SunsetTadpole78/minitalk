GREEN = \033[0;32m
YELLOW = \033[1;33m
ORANGE = \033[38;5;208m
RED = \033[0;31m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
CLEAR = \033[0m

CHECK = [✔ ]
CROSS = [✘]
ARROW = =>
INFO = [i]

SEPARATOR = "${CYAN}=====================================${CLEAR}"

SRC = src
INCLUDE = include ft_printf/include
OBJ = obj

INCLUDES = $(addprefix -I , $(INCLUDE))

CLIENT = client
SERVER = server

DEFAULT =	error.c	\
			utils.c

CLIENT_DEFAULT =	client/acknowledgment_utils.c	\
					client/client.c					\
					client/resend_utils.c			\
					client/sender.c					\
					$(DEFAULT)

SERVER_DEFAULT = 	server/header.c					\
					server/message_utils.c			\
					server/receiver.c				\
					server/server.c					\
					server/signature_utils.c		\
					server/type_utils.c				\
					$(DEFAULT)

CLIENT_FILES = $(addprefix $(SRC)/, $(CLIENT_DEFAULT))
SERVER_FILES = $(addprefix $(SRC)/, $(SERVER_DEFAULT))

CLIENT_OBJS = $(addprefix $(OBJ)/, $(CLIENT_DEFAULT:%.c=%.o))
SERVER_OBJS = $(addprefix $(OBJ)/, $(SERVER_DEFAULT:%.c=%.o))

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)
	@echo $(SEPARATOR)
	@echo "${GREEN}${CHECK} All targets are up to date!${CLEAR}"

bonus: all

$(CLIENT): $(OBJ) $(CLIENT_OBJS) $(FT_PRINTF)
	@echo $(SEPARATOR)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}${CLIENT}${ORANGE}...${CLEAR}"
	cc $(FLAGS) $(CLIENT_OBJS) $(FT_PRINTF) -o $(CLIENT)
	@echo "${GREEN}${CHECK} ${YELLOW}${CLIENT}${GREEN} compiled successfully!${CLEAR}"

$(SERVER): $(OBJ) $(SERVER_OBJS) $(FT_PRINTF)
	@echo $(SEPARATOR)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}${SERVER}${ORANGE}...${CLEAR}"
	cc $(FLAGS) $(SERVER_OBJS) $(FT_PRINTF) -o $(SERVER)
	@echo "${GREEN}${CHECK} ${YELLOW}${SERVER}${GREEN} compiled successfully!${CLEAR}"

$(FT_PRINTF):
	@echo $(SEPARATOR)
	@echo "${MAGENTA}${INFO} Building ${YELLOW}${FT_PRINTF}${MAGENTA}...${CLEAR}"
	make -C $(FT_PRINTF_DIR)
	@echo "${GREEN}${CHECK} ${YELLOW}${FT_PRINTF}${GREEN} built successfully!${CLEAR}"

$(OBJ):
	@echo $(SEPARATOR)
	@echo "${CYAN}${INFO} Creating ${YELLOW}${OBJ}${CYAN} directory...${CLEAR}"
	mkdir $(OBJ)
	@echo "${GREEN}${CHECK} ${YELLOW}${OBJ}${GREEN} directory created successfully!${CLEAR}"

$(OBJ)/%.o: $(SRC)/%.c
	@echo $(SEPARATOR)
	@echo "${ORANGE}${ARROW} Compiling ${YELLOW}$@${ORANGE}...${CLEAR}"
	mkdir -p $(dir $@)
	cc $(FLAGS) $< -c -o $@ $(INCLUDES)
	@echo "${GREEN}${CHECK} ${YELLOW}$@${GREEN} compiled successfully!${CLEAR}"

clean:
	@echo $(SEPARATOR)
	@echo "${RED}${CROSS} Cleaning object files...${CLEAR}"
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)
	rm -rf $(OBJ)
	make -C $(FT_PRINTF_DIR) clean
	@echo "${GREEN}${CHECK} Clean completed!${CLEAR}"

fclean: clean
	@echo $(SEPARATOR)
	@echo "${RED}${CROSS} Removing executables...${CLEAR}"
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make -C $(FT_PRINTF_DIR) fclean
	@echo "${GREEN}${CHECK} Full clean completed!${CLEAR}"

re: fclean all

.PHONY: all clean fclean re