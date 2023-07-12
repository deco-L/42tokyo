# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/12 13:29:47 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test

SRC			= test.c color.c c_to_i_color.c render_rect.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./mlx/

CC			= gcc

CCMLX		= cd ${MLX} && make && cd ./../

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -fr

RMMLX		= cd ${MLX} && make clean && cd ./../

AR			= ar rcs

all:		${NAME}

%.o:%.c
			$(CC) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):	${OBJS}
			${CCMLX} && \
			$(CC) $(OBJS) -I/usr/X11/include -Lmlx -lmlx_Darwin -L/usr/X11/include/../lib -Imlx -lXext -lX11 -o $(NAME)
clean:
			${RM} ${OBJS} && ${RMMLX}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re