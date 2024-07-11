#NORMAL
SRC_CLIENT =	./src/app/client.c \
				./src/app/client/check_args.c \
				./src/app/client/exit_error.c \

SRC_SERVER = ./src/app/server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CLIENT = client
SERVER = server

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
	@$(MAKE) -C $(LIBFT_SRC)
	@echo "Libft compiled"

$(CLIENT): $(LIBFT) $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
	@echo "Client Compiled!"

#RULES BONUS
$(SERVER): $(LIBFT) $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
	@echo "Server Compiled!"


#SOMETHING
all: $(CLIENT) $(SERVER)
	@echo "All Done"

bonus: all

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) clean -C $(LIBFT_SRC)

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(LIBFT_SRC)
	@echo "All Cleaned"

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re rebonus

