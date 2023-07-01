# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/01 14:26:37 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC			= so_long.c window_helper.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./minilibx_opengl_20191021/

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

AR			= ar rcs

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o} && \
			${CC} ${CFLAGS} -I ${MLX} -c -o $@

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RM} ${OBJS} && ${RM} && ${RM}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re