/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/13 21:34:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H



/*---include---*/
# include "../srcs/libft/libft_include/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h> //linux
# include <termios.h>
# include <termcap.h>
/*-------------*/



/*---Structure_Declaration---*/
typedef struct s_signal
{
	struct sigaction	action;
}				t_signal;

typedef struct s_init
{
	char		*command;
	t_signal	*signal;
}				t_init;
/*---------------------------*/



void	init_minishell(t_init *state);
void	standby_state(t_init *state);



/*---signal---*/
void	signal_minishell(struct sigaction action);
/*------------*/
#endif