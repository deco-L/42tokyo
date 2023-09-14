/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standby_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:36:44 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 13:36:34 by csakamot         ###   ########.fr       */
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
		built_in(state, state->exe, state->prompt);
		// printf("%zu, %s\n", count++, state->command);
		free(state->prompt);
	}
	return ;
}
