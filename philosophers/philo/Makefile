# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/09/10 22:18:28 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= philo
##-----------------------------##



##-----Directory Location------##
PRE			= ./srcs/

HEAD		= ./includes/
##-----------------------------##



##------------Srcs-------------##
SRC			= philo.c
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRC:.c=.o}}
##-----------------------------##



##----------conpiler-----------##
CFLAGS		= -Wall -Wextra -Werror
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o $@

${NAME}:	${OBJS}
			@echo "object file		compiled"
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "philo			created\n\n"
			@echo "         ___       ___       ___       ___       ___    "
			@echo "        /\  \     /\__\     /\  \     /\__\     /\  \   "
			@echo "       /::\  \   /:/__/_   _\:\  \   /:/  /    /::\  \  "
			@echo "      /::\:\__\ /::\/\__\ /\/::\__\ /:/__/    /:/\:\__\ "
			@echo "      \/\::/  / \/\::/  / \::/\/__/ \:\  \    \:\/:/  / "
			@echo "         \/__/    /:/  /   \:\__\    \:\__\    \::/  /  "
			@echo "                  \/__/     \/__/     \/__/     \/__/   "

# -fsanitize=address
clean:
			@${RM} ${OBJS}
			@echo "object file		removed"

fclean:		clean
			@${RM} ${NAME}
			@echo "philo			removed"

re:			fclean all

exe:		re
			@make -s clean

.PHONY:		all clean fclean re exe
##-----------------------------##