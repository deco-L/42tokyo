# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 13:05:55 by csakamot          #+#    #+#              #
#    Updated: 2023/06/29 13:36:51 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

SRC			=

OBJS		= ${SRC:.c=.o}

HEAD		= ./includes/

PRE			= ./srcs/

FTPRINTF	= ${addprefix ${PRE}, ft_printf/}

FTPRINTF_A	= ${addprefix ${FTPRINTF}, libftprintf.a}

CC			= cc

CCFTPRINTF	= cd ${FTPRINTF} && make && cd ./../..

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -fr

RMFTPRINTF	= cd ${FTPRINTF} && make fclean && cd ./../..

AR			= ar rcs

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CCFTPRINTF}
			${CC} ${CFLAGS} ${OBJS} -L. ${FTPRINTF_A} -o ${NAME}

clean:
			${RM} ${OBJS} && \
			${RMFTPRINTF}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re