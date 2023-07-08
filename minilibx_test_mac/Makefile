# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/08 20:07:14 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test

SRC			= test.c

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
			$(CC) -Imlx -c $< -o $@

$(NAME):	${OBJS}
			${CCMLX} && \
			$(CC) $(OBJS) -L. mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJS} && ${RMMLX}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re