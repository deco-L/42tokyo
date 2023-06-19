# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:04:47 by csakamot          #+#    #+#              #
#    Updated: 2023/06/16 16:22:02 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC			= push_swap.c

OBJS		= ${SRC:.c=.o}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

AR			= ar rcs

all:		$(NAME)

$(NAME):	${OBJS}
			${AR} 

ttt:
			cd src && make

clean:
			${RM} ${OBJS} && cd src && make fclean

fclean:
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re