# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/08/10 14:28:06 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= solong
##-----------------------------##



##-----Directory Location------##
PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./mlx/

LIBFT		= ${addprefix ${PRE}, libft/}
##-----------------------------##



##------------Srcs-------------##
SRC			= so_long.c create_window.c close_window.c key_hook.c init_map.c \
				init_texture.c create_map.c check_map.c move_player.c helper.c \
				error.c
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRC:.c=.o}}
##-----------------------------##



##----------conpiler-----------##
CFLAGS		= -Wall -Wextra -Werror

CCLIBFT		= cd ${LIBFT} && make && cd ./../../

CCMLX		= cd ${MLX} && make && cd ./../
##-----------------------------##



##------------remove-----------##
RMMLX		= cd ${MLX} && make clean && cd ./../

RMLIBFT		= cd ${LIBFT} && make fclean && cd ./../../
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			@$(CC) -I/usr/include -Imlx -c $< -o $@

$(NAME):	${OBJS}
			@echo "object file		compiled"
			@${CCMLX}
			@${CCLIBFT}
			@$(CC) $(CFLAGS) $(OBJS) -I/usr/X11/include -Lmlx -lmlx_Darwin -L/usr/X11/include/../lib \
															-Imlx -lXext -lX11  -Lsrcs ${ARCHIVES} -o $(NAME)
			@echo "created			solong"
# -fsanitize=address
clean:
			@${RM} ${OBJS}
			@${RMMLX}
			@${RMLIBFT}
			@echo "object file		removed"

fclean:		clean
			@${RM} ${NAME}
				@echo "solong			removed"

re:			fclean all

.PHONY:		all clean fclean re
##-----------------------------##