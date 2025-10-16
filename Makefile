# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 17:46:02 by mirokugo          #+#    #+#              #
#    Updated: 2025/10/13 22:27:05 by mirokugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR) -Iincludes

SRC_DIR = srcs
OBJ_DIR = objs

SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c

BONUS_SERVER_SRC = $(SRC_DIR)/server_bonus.c
BONUS_CLIENT_SRC = $(SRC_DIR)/client_bonus.c

SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_OBJ = $(OBJ_DIR)/client.o

BONUS_SERVER_OBJ = $(OBJ_DIR)/server_bonus.o
BONUS_CLIENT_OBJ = $(OBJ_DIR)/client_bonus.o

SERVER = server
CLIENT = client

BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

all: $(SERVER) $(CLIENT)

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER): $(LIBFT) $(BONUS_SERVER_OBJ)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJ) $(LIBFT) -o $(BONUS_SERVER)

$(BONUS_CLIENT): $(LIBFT) $(BONUS_CLIENT_OBJ)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJ) $(LIBFT) -o $(BONUS_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SERVER): $(LIBFT) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all clean fclean re
