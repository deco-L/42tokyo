# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 02:35:02 by yayoi             #+#    #+#              #
#    Updated: 2023/05/17 16:05:28 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a

SRC			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c\
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\

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