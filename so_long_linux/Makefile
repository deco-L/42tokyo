# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/08/10 22:04:53 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= solong
##-----------------------------##



##-----Directory Location------##
PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./mlx_linux/

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

CCLIBFT		= make -s -C srcs/libft

CCMLX		= make -s -i -C mlx_linux
##-----------------------------##



##------------remove-----------##
RMMLX		= cd ${MLX} && make -s clean && cd ./../

RMLIBFT		= cd ${LIBFT} && make -s fclean && cd ./../../
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			$(CC) -I/usr/include -Imlx -c $< -o $@

$(NAME):	${OBJS}
			@echo "object file		compiled"
			@${CCMLX}
			@${CCLIBFT}
			@$(CC) ${CFLAGS} -fsanitize=address $(OBJS) -L. ${ARCHIVES} \
				-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			@echo "created			solong\n\n"
			@echo "            ██████  ▒█████   ██▓     ▒█████   ███▄    █   ▄████ "
			@echo "          ▒██    ▒ ▒██▒  ██▒▓██▒    ▒██▒  ██▒ ██ ██   █  ██▒ ▀█▒"
			@echo "          ░ ▓██▄   ▒██░  ██▒▒██░    ▒██░  ██▒▓██  ██ ██▒▒██░▄▄▄░"
			@echo "            ▒   ██▒▒██   ██░▒██░    ▒██   ██░▓██▒  █▌██▒░▓█  ██▓"
			@echo "          ▒██████▒▒░ ████▓▒░░██████▒░ ████▓▒░▒██░   ███░░▒▓███▀▒"
			@echo "          ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒ "
			@echo "          ░ ░▒  ░ ░  ░ ▒ ▒░ ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░ "
			@echo "          ░  ░  ░  ░ ░ ░ ▒    ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░ "
			@echo "                ░      ░ ░      ░  ░    ░ ░           ░       ░ "
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

#			@echo "                                     .__                         "
#			@echo "                      __________     |  |   ____   ____    ____  "
#			@echo "                     /  ___/  _ \    |  |  /  _ \ /    \  / ___\ "
#			@echo "                     \___ (  <_> )   |  |_(  <_> )   |  \/ /_/  >"
#			@echo "                    /____  >____/____|____/\____/|___|  /\___  / "
#			@echo "                         \/    /_____/                \//_____/  "