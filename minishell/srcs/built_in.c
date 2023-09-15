/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:18:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/15 13:31:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	judge_built_in(t_init *state, char *exe_built_command)
{
	size_t	len;

	len = ft_strlen(exe_built_command);
	// printf("len : %zu, judge : %d\n", len, ft_strncmp(exe_built_command, "echo", len));
	if (!ft_strncmp(exe_built_command, "cd", len))
		built_in_cd();
	else if (!ft_strncmp(exe_built_command, "echo", len))
		built_in_echo();
	else if (!ft_strncmp(exe_built_command, "env", len))
		built_in_env();
	else if (!ft_strncmp(exe_built_command, "exit", len))
		built_in_exit(state);
	else if (!ft_strncmp(exe_built_command, "pwd", len))
		built_in_pwd();
	else if (!ft_strncmp(exe_built_command, "unset", len))
		built_in_unset();
	else
		return (1);
	return (0);
}
