# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 13:30:34 by mcraipea          #+#    #+#              #
#    Updated: 2019/12/02 13:55:27 by mcraipea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = cub3d

SRC = main.c \
	keyboard.c \
	map.c \
	texture.c \
	color.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) ./libft/libft.a $(CFLAGS) $(LDFLAGS)

lib:
	@(cd libft && $(MAKE))

clnlib:
	@(cd libft && $(MAKE) clean)

fclnlib:
	@(cd libft && $(MAKE) fclean)

clean: clnlib
	@/bin/rm -f $(OBJ)

fclean: clean fclnlib
	@/bin/rm -f $(NAME)

re: fclean all