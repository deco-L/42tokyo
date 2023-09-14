/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 18:12:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exe_command(t_init *state, char **command)
{
	char	*exe;

	exe = ft_strjoin(BINARY, command[0]);
	printf("exe:%s\n", exe);
	execve(exe, command, state->env);
	perror("execve");
	free(exe);
	return ;
}

void	external_command(t_init *state, t_exe *exe_built, char *prompt)
{
	int		status;

	status = 0;
	exe_built->command = ft_split(prompt, ' ');
	// exe_command(state, exe_built->command);
	exe_built->pid = fork();
	printf("process:%d\n", exe_built->pid);
	if (exe_built->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe_built->pid == 0)
	{
		printf("child\n");
		exe_command(state, exe_built->command);
		printf("ok!\n");
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(exe_built->pid, &status, 0);
	double_array_free(exe_built->command);
	return ;
}
