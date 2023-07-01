# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/01 20:33:21 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test

SRC			= test.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./minilibx-linux/

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

RMMLX		= cd ${MLX} && make clean && cd ./../

AR			= ar rcs

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
			${CC} ${CFLAGS} -I ${mlx} -c $< -o $@

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -L ${mlx} -l ${mlx} -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RM} ${OBJS} && ${RM} && ${RM}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re