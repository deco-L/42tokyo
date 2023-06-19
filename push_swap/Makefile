# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:04:47 by csakamot          #+#    #+#              #
#    Updated: 2023/06/19 17:24:21 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC			= push_swap.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

LIBFT		= ${addprefix ${PRE}, libft.a}

CCLIBFT		= cd ${PRE} && make && cd ..

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

RMLIBFT		= cd ${PRE} && make fclean && cd ..

AR			= ar rcs

all:		$(NAME)

.c.o:		
			${CC} -c -I ${HEAD} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CCLIBFT} && ${CC} ${LIBFT} ${OBJS} -o $(NAME)

clean:
			${RM} ${OBJS} && ${RMLIBFT}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re