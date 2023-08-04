# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/08/04 12:42:07 by csakamot         ###   ########.fr        #
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

PRINTF		= ${addprefix ${LIBFT}, printf/}

GNL			= ${addprefix ${LIBFT}, get_next_line/}
##-----------------------------##



##------------Srcs-------------##
SRC			= so_long.c create_window.c close_window.c key_hook.c init_map.c \
				init_texture.c create_map.c check_map.c helper.c error.c \

GNLSRCS		= get_next_line_bonus.c get_next_line_utils_bonus.c
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRC:.c=.o}}

GNLOBJS		= ${GNLSRCS:.c=.o}
##-----------------------------##



##----------conpiler-----------##
CC			= cc

CFLAGS		= -Wall -Wextra -Werror

CCLIBFT		= cd ${LIBFT} && make bonus && cd ./../../

CCPRINTF	= cd ${PRINTF} && make && cd ./../../../

CCGNL		= cd ${GNL} && ${CC} -c ${GNLSRCS} && ${AR} gnl.a ${GNLOBJS} && cd ./../../../

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
			${CCMLX} && \
			$(CC) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME):	${OBJS}
			${CCLIBFT} && \
			${CCPRINTF} && \
			${CCGNL} && \
			$(CC) ${CFLAGS} -fsanitize=address $(OBJS) -L. ${ARCHIVES} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#
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