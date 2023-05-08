# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 02:35:02 by yayoi             #+#    #+#              #
#    Updated: 2023/05/08 17:01:08 by sakamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC			= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c\
				main.c

OBJS		= ${SRC:.c=.o}

HEAD		= libft.h

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

AR			= ar r

all:		${NAME}

.c.o:		${CC} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all