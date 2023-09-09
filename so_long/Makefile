# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/09/09 13:14:33 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= so_long

NAME_BONUS	= so_long_bonus
##-----------------------------##



##-----Directory Location------##
HEAD		= ./includes/

PRE			= ./srcs/

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
				loop_hook_bonus.c
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${MANDATORY}, ${SRCS:.c=.o}}

OBJS_BONUS	= ${addprefix ${BONUS}, ${BONUS_SRCS:.c=.o}}
##-----------------------------##



##----------conpiler-----------##
CFLAGS		= -Wall -Wextra -Werror

CCLIBFT		= make -s -C srcs/libft
##-----------------------------##



##------------remove-----------##
RMLIBFT		= cd ${LIBFT} && make -s fclean && cd ./../../
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##



##--------Makefile rule--------##
EXE_NAME	= ${NAME}
OBJ			= ${OBJS}
ifdef WITH_BONUS
EXE_NAME	= ${NAME_BONUS}
OBJ 		= ${OBJS_BONUS}
endif
all:		${EXE_NAME}

bonus:
			@make -s WITH_BONUS=1

%.o:%.c
			@${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o $@

${EXE_NAME}:	${OBJ}
			@echo "object file		compiled"
			@${CCLIBFT}
			@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -Lsrcs ${ARCHIVES} -o ${EXE_NAME}
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

.PHONY:		all clean fclean re rebonus exe bonus
##-----------------------------##