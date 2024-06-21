SRC_CLIENT = ./src/app/client.c 
SRC_SERVER = ./src/app/server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIBFT_SRC = ./src/lib/libft
LIBFT = $(LIBFT_SRC)/libft.a

CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -s all -C $(LIBFT_SRC) > /dev/null
	@echo "Libft compiled"

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
	@echo "Client Compiled!"

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
	@echo "Server Compiled!"

all: $(LIBFT) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(LIBFT_SRC) > /dev/null
	@echo "All Done"

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) clean -C $(LIBFT_SRC) > /dev/null

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(LIBFT_SRC) > /dev/null
	@echo "All Cleaned"

re: fclean all

.PHONY: all clean fclean re

