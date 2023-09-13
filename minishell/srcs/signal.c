/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:50:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/13 13:58:34 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	(void)dummy;
	exit(EXIT_SUCCESS);
}

void	signal_minishell(t_signal *sig_act)
{
	sig_act->action.sa_sigaction = signal_handler;
	sigemptyset(&(sig_act->action).sa_mask);
	sig_act->action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &(sig_act->action), NULL);
	return ;
}
