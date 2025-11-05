# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 18:47:08 by MP9               #+#    #+#              #
#    Updated: 2025/11/05 21:02:43 by MP9              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_DIR = objs1
SERVER_DIR = objs2

CLIENTFILES = Sender/client.c  Sender/client_utils.c \

SERVERFILES = Receiver/server.c \

SERVEROBJS = $(SERVERFILES:Receiver/%.c=$(SERVER_DIR)/%.o)
CLIENTOBJS = $(CLIENTFILES:Sender/%.c=$(CLIENT_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes/ \

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENTOBJS)
	$(CC) $(CFLAGS) $(CLIENTOBJS) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVEROBJS)
	$(CC) $(CFLAGS) $(SERVEROBJS) $(LIBFT) -o $(SERVER_NAME)

$(SERVER_DIR)/%.o: Receiver/%.c includes/minitalk.h
	@mkdir -p $(SERVER_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_DIR)/%.o: Sender/%.c includes/minitalk.h
	@mkdir -p $(CLIENT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean:
		rm -rf $(CLIENT_DIR)
		rm -rf $(SERVER_DIR)
		$(MAKE) clean -C $(LIBFT_DIR)
		@echo "library and object files cleaned." 

fclean: clean
		rm -f $(CLIENT_NAME)
		rm -f $(SERVER_NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)
		@echo "Executable and library cleaned."

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all bonus clean fclean re