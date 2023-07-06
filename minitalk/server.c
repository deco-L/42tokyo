/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:48:14 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/06 16:01:33 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int						i;
	static volatile sig_atomic_t	g_char;
	char							c;

	dummy = NULL;
	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		;
	i++;
	c = 0xff & g_char;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		kill(info->si_pid, SIGUSR1);
		i = 0;
		g_char = 0;
	}
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	ft_printf("not good minitalk server pid=%d\n", getpid());
	ft_memset(&act1, 0, sizeof(sigaction));
	ft_memset(&act2, 0, sizeof(sigaction));
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act2.sa_mask, SIGUSR1);
	ft_printf("sa_flags = %d, sa_mask = %d\n", act1.sa_flags, act2.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &act1, NULL);
		sigaction(SIGUSR2, &act2, NULL);
		pause();
	}
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q server");
// }