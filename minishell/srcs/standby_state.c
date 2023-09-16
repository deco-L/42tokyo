/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/16 18:16:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	standby_state(t_init *state)
{
	while (1)
	{
		state->prompt = readline("minishell$");
		if (!*(state)->prompt)
		{
			free(state->prompt);
			continue ;
		}
		state->exe->command = ft_split(state->prompt, ' ');
		if (judge_built_in(state, state->exe->command))
			external_command(state, state->exe);
		free(state->prompt);
	}
	return ;
}
