# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 13:04:58 by pnielly           #+#    #+#              #
#    Updated: 2021/06/25 15:43:20 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------- Colors
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"


NAME = libft.a
SRC = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_tolower.c ./ft_toupper.c ./ft_maxmin.c ./ft_isempty.c
OBJ = ./ft_atoi.o ./ft_bzero.o ./ft_calloc.o ./ft_isalnum.o ./ft_isalpha.o ./ft_isascii.o ./ft_isdigit.o ./ft_isprint.o ./ft_memccpy.o ./ft_memchr.o ./ft_memcmp.o ./ft_memcpy.o ./ft_memmove.o ./ft_memset.o ./ft_strchr.o ./ft_strdup.o ./ft_strlcat.o ./ft_strlcpy.o ./ft_strlen.o ./ft_strncmp.o ./ft_strnstr.o ./ft_strrchr.o ./ft_tolower.o ./ft_toupper.o ./ft_maxmin.o ./ft_isempty.o
SRC2 = ./ft_itoa.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strjoin.c ./ft_strmapi.c ./ft_strtrim.c ./ft_substr.c
OBJ2 = ./ft_itoa.o ./ft_putchar_fd.o ./ft_putendl_fd.o ./ft_putnbr_fd.o ./ft_putstr_fd.o ./ft_split.o ./ft_strjoin.o ./ft_strmapi.o ./ft_strtrim.o ./ft_substr.o
SRC3 = ./ft_lstadd_back_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstclear_bonus.c ./ft_lstdelone_bonus.c ./ft_lstiter_bonus.c ./ft_lstlast_bonus.c ./ft_lstmap_bonus.c ./ft_lstnew_bonus.c ./ft_lstsize_bonus.c ./get_next_line.c ft_lstswap.c ft_has_duplicates.c ft_lst_rm_one.c ft_lstcopy.c ft_abs.c ft_isdelim.c ft_strcpy.c
OBJ3 = ./ft_lstadd_back_bonus.o ./ft_lstadd_front_bonus.o ./ft_lstclear_bonus.o ./ft_lstdelone_bonus.o ./ft_lstiter_bonus.o ./ft_lstlast_bonus.o ./ft_lstmap_bonus.o ./ft_lstnew_bonus.o ./ft_lstsize_bonus.o ./get_next_line.o ft_lstswap.o ft_has_duplicates.o ft_lst_rm_one.o ft_lstcopy.o ft_abs.o ft_isdelim.o ft_strcpy.o
HEADER = libft.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	@printf $(GREEN)"Libft compiled\n"$(EOC)

$(NAME):fclean
	@gcc $(FLAGS) -c $(SRC) $(SRC2) $(HEADER)
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)

bonus:	fclean
	@gcc $(FLAGS) -c $(SRC) $(SRC2) $(SRC3) $(HEADER)
	@ar rc $(NAME) $(OBJ) $(OBJ2) $(OBJ3)
	@ranlib $(NAME)

clean:
	@/bin/rm -f *.o *.gch

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
