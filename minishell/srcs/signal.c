/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:50:11 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/15 03:05:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	(void)dummy;
	if (signum == SIGINT)
	{
		printf("%d\n", info->si_pid);
		return ;
	}
	return ;
}

void	signal_minishell(struct sigaction action)
{
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);
	return ;
}
