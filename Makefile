SRC_CLIENT = ./src/app/client.c 
SRC_SERVER = ./src/app/server.c

SRCD_LIBFT = ./src/lib/libft

LIBFT = libft.a

CLIENT = client
SERVER = server

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(CLIENT):
	@$(CC) $(CC_FLAGS) $(SRC_CLIENT) $(SRCD_LIBFT)/$(LIBFT) -o $(CLIENT)
	@echo "Client Compiled!"

$(SERVER):
	@$(CC) $(CC_FLAGS) $(SRC_SERVER) $(SRCD_LIBFT)/$(LIBFT) -o $(SERVER)
	@echo "Server Compiled!"

$(LIBFT):
	@$(MAKE) -s all -C $(SRCD_LIBFT) > /dev/null
	@echo "libft Compiled!"

all: $(LIBFT) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(SRCD_LIBFT) > /dev/null
	@echo "All Done"

clean:
	@$(MAKE) clean -C $(SRCD_LIBFT) > /dev/null

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(SRCD_LIBFT) > /dev/null
	@echo "All Cleaned"

re: fclean all

.PHONY: all clean fclean re

