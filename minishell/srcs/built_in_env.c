/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:36:17 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/15 17:18:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	built_in_env(t_init *state)
{
	size_t	i;

	i = 0;
	printf("env:Not yet implemented.\n");
	while (state->env[i])
	{
		printf("%s\n", state->env[i]);
		i++;
	}
	return ;
}
