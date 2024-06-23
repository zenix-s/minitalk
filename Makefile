#NORMAL
SRC_CLIENT = ./src/app/client.c
SRC_SERVER = ./src/app/server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CLIENT = client
SERVER = server

#BONUS
SRC_CLIENT_BONUS = ./src/bonus/client_bonus.c
SRC_SERVER_BONUS = ./src/bonus/server_bonus.c

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# LIBFT
LIBFT_SRC = ./src/lib/libft
LIBFT = $(LIBFT_SRC)/libft.a

# UTILS
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#RULES
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -s all -C $(LIBFT_SRC) > /dev/null
	@echo "Libft compiled"

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
	@echo "Client Compiled!"

#RULES BONUS
$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
	@echo "Server Compiled!"

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)
	@echo "Client Compiled!"

$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)
	@echo "Server Compiled!"

#SOMETHING
all: $(LIBFT) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(LIBFT_SRC) > /dev/null
	@echo "All Done"
bonus: $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) fclean -C $(LIBFT_SRC) > /dev/null
	@echo "Bonus Done"

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@$(MAKE) clean -C $(LIBFT_SRC) > /dev/null

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) fclean -C $(LIBFT_SRC) > /dev/null
	@echo "All Cleaned"

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re rebonus

