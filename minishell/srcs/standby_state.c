/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 16:29:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	standby_state(t_init *state)
{
	size_t	count;

	count = 0;
	while (1)
	{
		state->prompt = readline("minishell$");
		// printf("%zu, %s\n", count++, state->prompt);
		external_command(state, state->exe, state->prompt);
		free(state->prompt);
	}
	return ;
}
