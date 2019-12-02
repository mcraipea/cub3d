# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 01:17:21 by mcraipea          #+#    #+#              #
#    Updated: 2019/12/02 13:55:46 by mcraipea         ###   ########.fr        #
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
			ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \

AR =	ar

HEADERS =	./includes

CFLAGS =	-g -Wall -Wextra -Werror -I $(HEADERS)

SRCS =	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = ${SRCS:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
			${AR} -sucr ${NAME} ${OBJS}
		
clean:
					rm -f ${OBJS} ${OBJS2}

fclean: 			clean
					rm -f ${NAME}

re:					fclean all

.PHONY: 			all clean fclean
