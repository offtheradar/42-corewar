# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 01:11:14 by ysibous           #+#    #+#              #
#    Updated: 2018/05/21 01:11:16 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += op.c
FILES += parse_args.c
FILES += read_cor.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a:
		make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT)