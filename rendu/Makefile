# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoat <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/09 15:42:19 by adoat             #+#    #+#              #
#    Updated: 2018/09/17 16:32:40 by adoat            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = srcs/algo.c srcs/check.c srcs/stock.c srcs/main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	gcc -L./libft -lft -o $(NAME) $(OBJ)

$(OBJ): %.o:%.c
	gcc -o $@ -c $< -Wall -Wextra -Werror

clean :
	make clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
