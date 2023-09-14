/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/15 06:03:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exe_ext_command(t_init *state, char **command)
{
	char	*exe;

	exe = ft_strjoin(BINARY, command[0]);
	printf("exe:%s\n", exe);
	execve(exe, command, state->env);
	perror("execve");
	free(exe);
	return ;
}

void	external_command(t_init *state, t_exe *exe_ext)
{
	int		status;

	status = 0;
	// exe_command(state, exe_built->command);
	exe_ext->pid = fork();
	printf("process:%d\n", exe_ext->pid);
	if (exe_ext->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe_ext->pid == 0)
	{
		// printf("child\n");
		exe_ext_command(state, exe_ext->command);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(exe_ext->pid, &status, 0);
	double_array_free(exe_ext->command);
	return ;
}
