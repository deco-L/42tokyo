/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/15 13:30:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	standby_state(t_init *state)
{
	while (1)
	{
		state->prompt = readline("minishell$");
		state->exe->command = ft_split(state->prompt, ' ');
		if (judge_built_in(state, state->exe->command[0]))
			external_command(state, state->exe);
		double_array_free(state->exe->command);
		free(state->prompt);
	}
	return ;
}
