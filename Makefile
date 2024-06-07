SRC_CLIENT = ./src/app/client.c 
SRC_SERVER = ./src/app/server.c

SRCD_PRINTF = ./src/lib/printf

PRINTF = libftprintf.a

CLIENT = client
SERVER = server

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(CLIENT):
	@$(CC) $(CC_FLAGS) $(SRC_CLIENT) $(SRCD_PRINTF)/$(PRINTF) -o $(CLIENT)
	@echo "Client Compiled!"

$(SERVER):
	@$(CC) $(CC_FLAGS) $(SRC_SERVER) $(SRCD_PRINTF)/$(PRINTF) -o $(SERVER)
	@echo "Server Compiled!"

$(PRINTF):
	@$(MAKE) -s all -C $(SRCD_PRINTF) > /dev/null
	@echo "Printf Compiled!"

all: $(PRINTF) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(SRCD_PRINTF) > /dev/null
	@echo "All Done"

clean:
	@$(MAKE) clean -C $(SRCD_PRINTF) > /dev/null

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) fclean -C $(SRCD_PRINTF) > /dev/null
	@echo "All Cleaned"

re: fclean all

.PHONY: all clean fclean re

