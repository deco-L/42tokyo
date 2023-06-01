# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 14:31:10 by csakamot          #+#    #+#              #
#    Updated: 2023/06/01 13:58:47 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\

PRINTF_SRCS	= ft_printf.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRINTF_OBJS	= ${PRINTF_SRCS:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

NAME		= libftprintf.a

RM			= rm -f

CC			= cc

CFLAGS 		= -Wall -Wextra -Werror

AR			= ar rcs

all:		$(NAME)

.c.o:
			${CC} ${CFAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${PRINTF_OBJS}
			${AR} ${NAME} ${PRINTF_OBJS} ${OBJS}

clean:
			rm -f ${OBJS} ${PRINTF_OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re