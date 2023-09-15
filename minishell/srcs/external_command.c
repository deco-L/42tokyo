/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/15 12:54:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exe_ext_command(t_init *state, char **command)
{
	char	*exe;

	exe = ft_strjoin(BINARY, command[0]);
	printf("exe:%s env:%s\n", exe, state->env[0]);
	execve(exe, command, state->env);
	perror("execve");
	free(exe);
	return ;
}

void	external_command(t_init *state, t_exe *exe_ext)
{
	int		status;

	status = 0;
	exe_ext->pid = fork();
	printf("process:%d, %s\n", exe_ext->pid, state->env[1]);
	if (exe_ext->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe_ext->pid == 0)
		exe_ext_command(state, exe_ext->command);
	else
		waitpid(exe_ext->pid, &status, 0);
	return ;
}
