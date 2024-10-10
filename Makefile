# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonfer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 13:10:26 by antonfer          #+#    #+#              #
#    Updated: 2024/08/05 13:10:28 by antonfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRCS_CLIENT = src/client.c src/ft_printf.c src/minitalk_utils.c
SRCS_SERVER = src/server.c src/ft_printf.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(NAME): $(CLIENT) $(SERVER)

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(FLAGS) -o $(CLIENT) $(OBJS_CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(FLAGS) -o $(SERVER) $(OBJS_SERVER)

clean:
	/bin/rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	/bin/rm -f $(CLIENT) $(SERVER)

re: fclean all
