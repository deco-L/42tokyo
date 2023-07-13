# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/07/13 13:45:26 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= so_long
##-----------------------------##



##------------Srcs-------------##
SRC			= test.c

GNLSRCS		= get_next_line_bonus.c get_next_line_utils_bonus.c
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRC:.c=.o}}

GNLOBJS		= ${GNLSRCS:.c=.o}
##-----------------------------##



##-----Directory Location------##
PRE			= ./srcs/

HEAD		= ./includes/

MLX			= ./mlx/

LIBFT		= ${addprefix ${PRE}, libft/}

PRINTF		= ${addprefix ${LIBFT}, printf/}

GNL			= ${addprefix ${LIBFT}, get_next_line/}
##-----------------------------##



##----------conpiler-----------##
CC			= cc

CFLAGS		= -Wall -Wextra -Werror

CCLIBFT		= cd ${LIBFT} && make bonus && cd ./../../

CCPRINTF	= cd ${PRINTF} && make && cd ./../../../

CCGNL		= cd ${GNL} && ${CC} -c ${CFLAGS} ${GNLSRCS} && ${AR} gnl.a ${GNLOBJS} && cd ./../../../

CCMLX		= cd ${MLX} && make && cd ./../
##-----------------------------##



##------------remove-----------##
RM			= rm -fr

RMMLX		= cd ${MLX} && make clean && cd ./../

RMLIBFT		= cd ${LIBFT} && make fclean && cd ./../../

RMPRINTF	= cd ${PRINTF} && make fclean && cd ./../../../

RMGNL		= cd ${GNL} && ${RM} ${GNLOBJS} gnl.a && cd ./../../../
##-----------------------------##



##-----------archive-----------##
AR			= ar rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a} ${addprefix ${PRINTF}, libftprintf.a} ${addprefix ${GNL}, gnl.a}
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			$(CC) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):	${OBJS}
			${CCMLX} && \
			${CCLIBFT} && \
			${CCPRINTF} && \
			${CCGNL} && \
			$(CC) $(OBJS) -I/usr/X11/include -Lmlx -lmlx_Darwin -L/usr/X11/include/../lib \
							-Imlx -lXext -lX11  -Lsrcs ${ARCHIVES} -o $(NAME)
clean:
			${RM} ${OBJS} && \
			${RMMLX} && \
			${RMLIBFT} && \
			${RMPRINTF} && \
			${RMGNL}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
##-----------------------------##