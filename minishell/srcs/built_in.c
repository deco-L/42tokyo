/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 13:41:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exe_command(t_init *state, char **command)
{
	execve(command[0], command, state->env);
	return ;
}

void	built_in(t_init *state, t_exe *exe_built, char *prompt)
{
	exe_built->pid = fork();
	exe_built->command = ft_split(prompt, ' ');
	if (exe_built->pid > 0)
	{
		exe_command(state, exe_built->command);
		return ;
	}
	else if (exe_built->pid == 0)
	{
		return ;
	}
	double_array_free(exe_built->command);
	return ;
}
