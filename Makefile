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

# Libft Variables #
LIBFT	=	libft/libft.a

# Mandatory Variables #
SRC_S	=	server.c
SRC_C	=	client.c
BNS_S	=	server_bonus.c
BNS_C	=	client_bonus.c

# Transform to Objects #
OBJ_S	=	$(SRC_S:.c=.o)
OBJ_C	=	$(SRC_C:.c=.o)
OBJ_BS	=	$(BNS_S:.c=.o)
OBJ_BC	=	$(BNS_C:.c=.o)

# Compiling Variables #
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

# Compiling #
all:		libft server client

libft:
			@$(MAKE) -C ./libft all

server:		$(OBJ_S) $(LIBFT)
			@$(CC) $(CFLAG) $(OBJ_S) $(LIBFT) -o server
			@printf "$(_SUCCESS) Server ready.\n"

client:		$(OBJ_C) $(LIBFT)
			@$(CC) $(CFLAG) $(OBJ_C) $(LIBFT) -o client
			@printf "$(_SUCCESS) Client ready.\n"

bonus:		libft $(OBJ_BS) $(OBJ_BC) $(LIBFT)
			@$(CC) $(CFLAG) $(OBJ_BS) $(LIBFT) -o server_bonus
			@printf "$(_SUCCESS) Server_Bonus ready.\n"
			@$(CC) $(CFLAG) $(OBJ_BC) $(LIBFT) -o client_bonus
			@printf "$(_SUCCESS) Client_Bonus ready.\n"

clean:
			$(RM) $(OBJ_S) $(OBJ_C)
			$(RM) $(OBJ_BS) $(OBJ_BC)
			$(MAKE) -C ./libft clean
			@printf "$(_INFO) Clean done.\n"

fclean:		clean
			$(RM) server client
			$(RM) server_bonus client_bonus
			$(MAKE) -C ./libft fclean
			@printf "$(_INFO) FClean done.\n"

re:			fclean all

.PHONY:		all libft clean fclean re
