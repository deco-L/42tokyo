# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/01 19:07:03 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test

SRC			= test.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./minilibx_opengl_20191021/

CC			= cc

CCMLX		= cd ${MLX} && make && cd ./../

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

RMMLX		= cd ${MLX} && make clean && cd ./../

AR			= ar rcs

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
			${CC} ${CFLAGS} -I ${MLX} -c $< -o $@

$(NAME):	${OBJS}
			${CCMLX} && \
			${CC} ${CFLAGS} ${OBJS} libmlx.a -L ${MLX} -l ${MLX} -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RMMLX} && \
			${RM} ${OBJS} && ${RM} && ${RM}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re