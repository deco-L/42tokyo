/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 16:22:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exe_command(t_init *state, char **command)
{
	char	*exe;

	exe = ft_strjoin(BINARY, command[0]);
	execve(exe, command, state->env);
	free(exe);
	return ;
}

void	external_command(t_init *state, t_exe *exe_built, char *prompt)
{
	int		status;
	pid_t	wait;

	status = 0;
	exe_built->command = ft_split(prompt, ' ');
	exe_command(state, exe_built->command);
	exe_built->pid = fork();
	printf("process:%d\n", exe_built->pid);
	if (exe_built->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe_built->pid == 0)
	{
		printf("child:%s\n", exe_built->command[0]);
		exe_command(state, exe_built->command);
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait = waitpid(exe_built->pid, &status, 0);
		printf("parent\n");
		exit(EXIT_SUCCESS);
	}
	double_array_free(exe_built->command);
	return ;
}
