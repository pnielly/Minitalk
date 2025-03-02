# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 15:17:37 by user42            #+#    #+#              #
#    Updated: 2021/07/05 16:01:09 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------- Executables
NAME_S=server
NAME_C=client
NAME_CHECK_TIME=client_clock

# ------------- Commands
CC=gcc
FLAGS=-Wall -Wextra -Werror

# ------------- SRCS, OBJ and INC
INC=-I includes

SRC_DIR=srcs/
SRC_S=server.c ft_error.c ft_bzero.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c
SRC_C=client.c ft_error.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_atoi.c ft_bzero.c
SRC_CHECK_TIME=client_clock.c ft_error.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_atoi.c ft_bzero.c

OBJ_DIR=obj/
OBJ_S=$(addprefix $(OBJ_DIR),$(SRC_S:.c=.o))
OBJ_C=$(addprefix $(OBJ_DIR),$(SRC_C:.c=.o))
OBJ_CHECK_TIME=$(addprefix $(OBJ_DIR),$(SRC_CHECK_TIME:.c=.o))

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

$(NAME_S): $(OBJ_S)
	@$(CC) $(FLAGS) $(OBJ_S) -o $(NAME_S)

$(NAME_C): $(OBJ_C)
	@$(CC) $(FLAGS) $(OBJ_C) -o $(NAME_C)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf $(CYAN)"Compiling $@\n"$(EOC)
	@$(CC) $(FLAGS) -o $@ -c $< $(INC)

time:	$(NAME_S) $(NAME_CHECK_TIME)
	@printf $(GREEN)"Server compiled\n"
	@printf "client_clock compiled\n"$(EOC)

$(NAME_CHECK_TIME): $(OBJ_CHECK_TIME)
	@$(CC) $(FLAGS) $(OBJ_CHECK_TIME) -o $(NAME_CHECK_TIME)

clean:
	@rm -rf *.gch obj
	@printf $(RED)"Objects removed\n"$(EOC)

fclean: clean
	@rm -rf $(NAME_S) $(NAME_C) $(NAME_CHECK_TIME)
	@printf $(RED)"Executables removed\n"$(EOC)

re: fclean all

