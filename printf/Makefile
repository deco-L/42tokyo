# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 14:31:10 by csakamot          #+#    #+#              #
#    Updated: 2023/06/10 16:03:24 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_bzero.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_printf.c\
				ft_check_printf.c ft_process.c ft_putnbr_base_fd_cnt.c ft_strlen.c\

OBJS		= ${SRC:.c=.o}

NAME		= libftprintf.a

RM			= rm -f

CC			= cc

CFLAGS 		= -Wall -Wextra -Werror

AR			= ar rcs

all:		$(NAME)

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re