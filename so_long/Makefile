# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 12:07:59 by csakamot          #+#    #+#              #
#    Updated: 2023/06/27 12:18:20 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC			=

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

LIBFT		= ${addprefix ${PRE}, libft/}

FTPRINTF	= ${addprefix ${PRE}, ft_printf/}

LIBFT_A		= ${addprefix ${LIBFT}, libft.a}

FTPRINTF_A	= ${addprefix ${FTPRINTF}, libftprintf.a}

CCLIBFT		= cd ${LIBFT} && make bonus && cd ./../..

CCFTPRINTF	= cd ${FTPRINTF} && make && cd ./../..

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

RMLIBFT		= cd ${LIBFT} && make fclean && cd ./../..

RMFTPRINTF	= cd ${FTPRINTF} && make fclean && cd ./../..

AR			= ar rcs

all:		${NAME}

.c.o:
			${CC} -c -I ${HEAD} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CCLIBFT} && \
			${CCFTPRINTF} && \
			${CC} ${OBJS} -L. ${LIBFT_A} ${FTPRINTF_A} -o ${NAME}

clean:
			${RM} ${OBJS} && ${RMLIBFT} && ${RMFTPRINTF}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re