# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/09/03 14:06:19 by csakamot         ###   ########.fr        #
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
SRC			= 
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
			$(CC) -I/usr/include -Imlx -c $< -o $@

$(NAME):	${OBJS}
			@echo "object file		compiled"
			@$(CC) $(CFLAGS) $(OBJS) -I/usr/X11/include ${ARCHIVES} -o $(NAME)
			@echo "philo			created\n\n"
# -fsanitize=address
clean:
			@${RM} ${OBJS}
			@echo "object file		removed"

fclean:		clean
			@${RM} ${NAME}
			@echo "solong			removed"

re:			fclean all

exe:		re
			@make -s clean

.PHONY:		all clean fclean re
##-----------------------------##