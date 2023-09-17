/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/17 02:20:17 by csakamot         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h> //linux
# include <termios.h>
# include <termcap.h>
/*-------------*/

/*---path---*/
# define BINARY	"/bin/"
/*----------*/

/*---Structure_Declaration---*/
typedef struct s_signal
{
	struct sigaction	action;
}				t_signal;

typedef struct s_exe
{
	pid_t	pid;
	size_t	exe_flag;
	char	**command;
}				t_exe;

typedef struct s_init
{
	char		*prompt;
	t_exe		*exe;
	t_signal	*signal;
}				t_init;
/*---------------------------*/

void	init_minishell(t_init *state);
void	standby_state(t_init *state);

/*---built_in---*/
int		judge_built_in(t_init *state, char **exe_buil_command);
void	built_in_cd(void);
void	built_in_echo(void);
void	built_in_env(t_init *state);
void	built_in_exit(t_init *state);
void	built_in_pwd(void);
void	built_in_unset(void);
/*--------------*/

/*---external_command---*/
void	external_command(t_init *state, t_exe *exe_built);
/*---------------------*/

/*---signal---*/
void	signal_minishell(struct sigaction action);
/*------------*/

/*---free---*/
void	double_array_free(char **array);
/*----------*/
#endif