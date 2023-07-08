# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/08 15:19:48 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test

SRC			= test.c minilibx_test_helper.c minilibx_color_helper.c minilibx_win_helper.c minilibx_render_helper.c \
				make_rectangle.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./mlx/

CC			= cc

CCMLX		= cd ${MLX} && make && cd ./../

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

RMMLX		= cd ${MLX} && make clean && cd ./../

AR			= ar rcs

all:		${NAME}

%.o:%.c
			$(CC) ${CFLAGS} -Imlx -O3 -c $< -o $@

$(NAME):	${OBJS}
			${CCMLX} && \
			$(CC) $(OBJS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
			${RM} ${OBJS} && ${RMMLX}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re