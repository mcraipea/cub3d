# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 01:17:21 by mcraipea          #+#    #+#              #
#    Updated: 2019/12/16 19:10:45 by mcraipea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS_PATH =	./

SRCS_NAME = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
			ft_toupper.c ft_strdup.c ft_atoi.c ft_calloc.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strcpy.c \
			ft_strmapi.c ft_strchr_gnl.c ft_strnjoin_gnl.c get_next_line.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_strsub.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			ft_lstlast_bonus.c ft_lstnew_bonus.c ft_strsplit.c ft_strnew.c\
			ft_lstsize_bonus.c ft_countwords.c ft_memdel.c ft_strdel.c \
			ft_lstrev.c ft_memalloc.c ft_lstcount.c ft_splitdel.c \
			ft_swap.c \

BMP	=	./bmp/encode.c ./bmp/bitmap.c ./bmp/check.c ./bmp/header.c \
		./bmp/rgb_encode.c ./bmp/utils.c

AR =	ar

HEADERS =	./includes

CFLAGS =	-g -Wall -Wextra -Werror -I $(HEADERS)

SRCS =	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = ${SRCS:.c=.o}

BMPS = $(BMP:.c=.o)

all:	${NAME}

$(NAME):	${OBJS} $(BMPS)
			${AR} -sucr ${NAME} ${OBJS} $(BMPS)
		
clean:
					rm -f ${OBJS} ${OBJS2} $(BMPS)

fclean: 			clean
					rm -f ${NAME}

re:					fclean all

.PHONY: 			all clean fclean
