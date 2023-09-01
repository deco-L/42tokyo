# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/09/01 23:10:27 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= solong

NAME_BONUS	= solong_bonus
##-----------------------------##



##-----Directory Location------##
HEAD		= ./includes/

PRE			= ./srcs/

MLX			= ./mlx_linux/

MANDATORY	= ${addprefix ${PRE}, srcs_mandatory/}

BONUS		= ${addprefix ${PRE}, srcs_bonus/}

LIBFT		= ${addprefix ${PRE}, libft/}
##-----------------------------##



##------------Srcs-------------##
SRCS		= so_long.c create_window.c close_window.c key_hook.c \
				init_map.c init_texture.c create_map.c check_map1.c \
				check_map2.c check_map3.c move_player.c helper.c error.c \

BONUS_SRCS	= so_long_bonus.c create_window_bonus.c close_window_bonus.c key_hook_bonus.c \
				init_map_bonus.c init_texture_bonus.c create_map_bonus.c check_map1_bonus.c \
				check_map2_bonus.c check_map3_bonus.c move_player_bonus.c helper_bonus.c error_bonus.c \
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${MANDATORY}, ${SRCS:.c=.o}}

OBJS_BONUS	= ${addprefix ${BONUS}, ${BONUS_SRCS:.c=.o}}
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

EXE_NAME	= ${NAME}
OBJ			= ${OBJS}
ifdef WITH_BONUS
EXE_NAME	= ${NAME_BONUS}
OBJ 		= ${OBJS_BONUS}
endif
bonus:
			@make -s WITH_BONUS=1

%.o:%.c
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o $@

$(NAME):	${OBJ}
			@echo "object file		compiled"
			@${CCMLX}
			@${CCLIBFT}
			@${CC} ${CFLAGS} -fsanitize=address $(OBJ) -L. ${ARCHIVES} \
				-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${EXE_NAME}
			@echo "solong			created\n\n"
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
			@${RM} ${OBJS_BONUS}
			@${RMMLX}
			@${RMLIBFT}
			@echo "object file		removed"

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${NAME_BONUS}
			@echo "exevutable file		removed"

re:			fclean all

rebonus:	fclean bonus

exe:		all bonus
			@make -s clean

.PHONY:		all clean fclean re exe
##-----------------------------##

#			@echo "                                     .__                         "
#			@echo "                      __________     |  |   ____   ____    ____  "
#			@echo "                     /  ___/  _ \    |  |  /  _ \ /    \  / ___\ "
#			@echo "                     \___ (  <_> )   |  |_(  <_> )   |  \/ /_/  >"
#			@echo "                    /____  >____/____|____/\____/|___|  /\___  / "
#			@echo "                         \/    /_____/                \//_____/  "