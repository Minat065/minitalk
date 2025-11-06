# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirokugo <mirokugo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 17:46:02 by mirokugo          #+#    #+#              #
#    Updated: 2025/11/06 22:51:30 by mirokugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR) -Iincludes

SRC_DIR = srcs
OBJ_DIR = objs

SERVER_SRC = $(SRC_DIR)/server.c \
			 $(SRC_DIR)/server_utils.c
CLIENT_SRC = $(SRC_DIR)/client.c \
			 $(SRC_DIR)/client_utils.c

SERVER_OBJ = $(OBJ_DIR)/server.o \
			 $(OBJ_DIR)/server_utils.o
CLIENT_OBJ = $(OBJ_DIR)/client.o \
			 $(OBJ_DIR)/client_utils.o

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

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
# 	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
