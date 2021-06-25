# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 15:17:37 by user42            #+#    #+#              #
#    Updated: 2021/06/25 18:16:57 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------- Executables
NAME_S=server
NAME_C=client
LIBFT=libft/libft.a

# ------------- Commands
CC=gcc
FLAGS=-Wall -Wextra -Werror

# ------------- SRCS, OBJ and INC
INC=-I includes
SRC_S=server.c ft_error.c
SRC_C=client.c ft_error.c

OBJ_DIR=obj/
OBJ_S=$(addprefix $(OBJ_DIR),$(SRC_S:.c=.o))
OBJ_C=$(addprefix $(OBJ_DIR),$(SRC_C:.c=.o))

# ------------- Colors
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

# ------------- Rules

all: $(NAME_S) $(NAME_C)
	@printf $(GREEN)"Server compiled\n"
	@printf "Client compiled\n"$(EOC)

$(NAME_S): $(LIBFT) $(OBJ_S)
	@$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)

$(NAME_C): $(LIBFT) $(OBJ_C)
	@$(CC) $(FLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@printf $(CYAN)"Compiling $@\n"$(EOC)
	@$(CC) $(FLAGS) -o $@ -c $< $(INC) -L $(LIBFT)

$(LIBFT):
	@printf $(CYAN)"Compiling $@\n"$(EOC)
	@make re -C libft/ --silent

clean:
	@make clean -C libft/ --silent
	@rm -rf *.gch obj
	@printf $(RED)"Objects removed\n"$(EOC)

fclean: clean
	@make fclean -C libft/ --silent
	@rm -rf $(NAME_S) $(NAME_C)
	@printf $(RED)"Executables removed\n"$(EOC)

re: fclean all

