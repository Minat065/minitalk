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

INCLUDES = -I$(LIBFT_DIR)

SERVER_SRC = server.c
CLIENT_SRC = client.c

BONUS_SERVER_SRC = server_bonus.c
BONUS_CLIENT_SRC = client_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)

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

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SERVER): $(LIBFT) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all clean fclean re
