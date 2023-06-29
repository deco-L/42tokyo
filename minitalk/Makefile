# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 13:05:55 by csakamot          #+#    #+#              #
#    Updated: 2023/06/29 16:48:33 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CRIENT_SRC	= client.c

SERVER_SRC	= server.c

SRC			= ${CRIENT_SRC} ${SERVER_OBJS}

OBJS		= ${SRC:.c=.o}

CLIENT_OBJS	= ${CRIENT_SRC:.c=.o}

SERVER_OBJS	= ${SERVER_SRC:.c=.o}

HEAD		= ./includes/

PRE			= ./srcs/

LIBFT		= ${addprefix ${PRE}, libft/}

FTPRINTF	= ${addprefix ${PRE}, ft_printf/}

LIBFT_A		= ${addprefix ${LIBFT}, libft.a}

FTPRINTF_A	= ${addprefix ${FTPRINTF}, libftprintf.a}

CC			= cc

CCLIBFT		= cd ${LIBFT} && make bonus && cd ./../..

CCFTPRINTF	= cd ${FTPRINTF} && make && cd ./../..

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -fr

RMLIBFT		= cd ${LIBFT} && make fclean && cd ./../..

RMFTPRINTF	= cd ${FTPRINTF} && make fclean && cd ./../..

AR			= ar rcs

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CCLIBFT} && \
			${CCFTPRINTF} && \
			${CC} ${CFLAGS} ${CLIENT_OBJS} -L. ${LIBFT_A} ${FTPRINTF_A} -o client
			${CC} ${CFLAGS} ${SERVER_OBJS} -L. ${LIBFT_A} ${FTPRINTF_A} -o server

clean:
			${RM} ${OBJS} && \
			${RMLIBFT} && \
			${RMFTPRINTF}

fclean:		clean
			${RM} client server

re:			fclean all

.PHONY:		all clean fclean re