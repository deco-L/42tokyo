# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:04:47 by csakamot          #+#    #+#              #
#    Updated: 2023/07/28 22:29:34 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC			= push_swap.c error.c error_check.c std_input_error_helper.c input_arg.c \
				input_arg_helper.c nodeinput_helper.c node_helper.c main_sort.c support.c \
				sort_rule.c threesort_helper.c fewsort_helper.c argssort_helper.c sort_helper.c \
				format_input.c argssort_rtn_helper.c argssort_push_helper.c atoi_push_swap.c

OBJS		= ${SRC:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

LIBFT		= ${addprefix ${PRE}, libft/}

FTPRINTF	= ${addprefix ${PRE}, ft_printf/}

LIBFT_A		= ${addprefix ${LIBFT}, libft.a}

FTPRINTF_A	= ${addprefix ${FTPRINTF}, libftprintf.a}

CCLIBFT		= cd ${LIBFT} && make bonus && cd ./../..

CCFTPRINTF	= cd ${FTPRINTF} && make && cd ./../..

CC			= cc

CFLAGS		= -Wall -Wextra -Werror
#-fsanitize=address

RM			= rm -fr

RMLIBFT		= cd ${LIBFT} && make fclean && cd ./../..

RMFTPRINTF	= cd ${FTPRINTF} && make fclean && cd ./../..

AR			= ar rcs

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CCLIBFT} && \
			${CCFTPRINTF} && \
			${CC} ${CFLAGS} ${OBJS} -L. ${LIBFT_A} ${FTPRINTF_A}  -o $(NAME)

clean:
			${RM} ${OBJS} && ${RMLIBFT} && ${RMFTPRINTF}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re