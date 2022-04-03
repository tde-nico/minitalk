# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-nico <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 17:37:01 by tde-nico          #+#    #+#              #
#    Updated: 2022/02/08 16:22:28 by tde-nico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	./src_server/server.c \
				./src_common/client_functions.c \
				./src_common/server_functions.c \
				./src_common/utils.c
CLIENT		=	./src_client/client.c \
				./src_common/client_functions.c \
				./src_common/server_functions.c \
				./src_common/utils.c
LIBFT		=	make -C libft
LIB			=	libft/libft.a
SERVER_SRC	=	$(SERVER)
SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
CLIENT_SRC	=	$(CLIENT)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)
OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)
GCC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I include
SERVER_NAME	=	server
CLIENT_NAME	=	client
NAME		=	minitalk

all: $(NAME)

$(NAME): start ft_server ft_client

start:
	$(LIBFT)

ft_server: $(SERVER_OBJS)
	$(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)

ft_client: $(CLIENT_OBJS)
	$(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	make fclean -C libft

.c.o:
	${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all minitalk server client clean fclean re libft
