/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 14:34:40 by csakamot         ###   ########.fr       */
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
	int		status;

	status = 0;
	printf("process\n");
	exe_built->pid = fork();
	exe_built->command = ft_split(prompt, ' ');
	if (exe_built->pid < 0)
		exit(EXIT_FAILURE);
	else if (exe_built->pid > 0)
	{
		waitpid(exe_built->pid, &status, WUNTRACED);
		printf("parent\n");
		exit(EXIT_SUCCESS);
	}
	else if (exe_built->pid == 0)
	{
		printf("child\n");
		sleep(2);
		// exe_command(state, exe_built->command);		
		exit(EXIT_SUCCESS);
	}
	double_array_free(exe_built->command);
	return ;
}
