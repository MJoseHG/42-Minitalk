# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahernan <mahernan@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 11:03:56 by mahernan          #+#    #+#              #
#    Updated: 2022/08/10 11:04:09 by mahernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name #
NAME	=
CLIENT	=	client
SERVER	=	server

# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# Mandatory Variables #
SRC_C	=	client.c
SRC_S	=	server.c
INC		=	-I. -I$(LIBFT_DIR)

# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

# Compiling #
all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) Server ready.\n"

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) Client ready.\n"


$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) Client removed.\n"
	@printf "$(_INFO) Server removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) Client removed.\n"
	@printf "$(_INFO) Server removed.\n"

re: fclean all

.PHONY: all clean fclean re
