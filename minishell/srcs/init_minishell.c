/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:38 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/13 13:18:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_minishell(t_init *state)
{
	t_signal	sig_act;

	ft_memset(state, 0, sizeof(t_init));
	ft_memset(&sig_act, 0, sizeof(t_signal));
	state->signal = &sig_act;
	return ;
}