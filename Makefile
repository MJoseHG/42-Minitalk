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
BONUS_C	=	client_bonus
BONUS_S	=	server_bonus

# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# Mandatory Variables #
SRC_C	=	client.c
SRC_S	=	server.c
BNS_C	=	client_bonus.c
BNS_S	=	server_bonus.c
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
all: $(SERVER) $(CLIENT) $(BONUS_S) $(BONUS_C)

$(NAME): all

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) Server ready.\n"

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) Client ready.\n"

$(BONUS_S): $(LIBFT)
	@ $(CC) $(CFLAG) $(BNS_S) $(LIBFT) $(INC) -o $(BONUS_S)
	@printf "$(_SUCCESS) Server_Bonus ready.\n"

$(BONUS_C): $(LIBFT)
	@ $(CC) $(CFLAG) $(BNS_C) $(LIBFT) $(INC) -o $(BONUS_C)
	@printf "$(_SUCCESS) Client_Bonus ready.\n"

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER) $(BONUS_C) $(BONUS_S)
	@printf "$(_INFO) Client removed.\n"
	@printf "$(_INFO) Server removed.\n"
	@printf "$(_INFO) Client_Bonus removed.\n"
	@printf "$(_INFO) Server_Bonus removed.\n"

fclean:
	@ $(MAKE) fclean clean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER) $(BONUS_C) $(BONUS_S)
	@printf "$(_INFO) Client removed.\n"
	@printf "$(_INFO) Server removed.\n"
	@printf "$(_INFO) Client_Bonus removed.\n"
	@printf "$(_INFO) Server_Bonus removed.\n"

re: fclean all

mandatory: $(CLIENT) $(SERVER) $(BNS_C) $(BNS_S)

bonus: mandatory

.PHONY: all clean fclean re mandatory bonus