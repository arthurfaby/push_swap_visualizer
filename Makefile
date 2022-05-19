# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/05/19 18:06:52 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

SRCS =	main.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		read.c \
		parse.c \
		lst.c

CC = gcc

INCS = .

MLX = minilibx
LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I$(MLX) -L$(MLX) -lmlx -lXext -lX11 -lm -I$(INCS) -I$(LIBFT) -L$(LIBFT) -lft

RM = rm -f

all: $(NAME)

clean:
#	make clean -C $(MLX)
	$(RM)

fclean: clean
#	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

$(NAME):
#	make re -C $(MLX)
#	make re -C $(LIBFT)
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS)

.PHONY: all clean fclean re
