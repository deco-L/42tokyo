/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:48:14 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/07 16:42:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_signal_error(void)
{
	ft_putstr_fd("Signal Error.\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_put_message(char *c, int *pid, volatile sig_atomic_t *cbuff)
{
	*c = 0xff & *cbuff;
	*cbuff = 0;
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		if (kill(*pid, SIGUSR1) == -1)
			ft_signal_error();
		return (0);
	}
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int						i;
	static int						client_pid;
	static int						current_pid;
	static volatile sig_atomic_t	charbuff;
	static char						c;

	(void)dummy;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		i = 0;
		c = 0;
		charbuff = 0;
	}
	charbuff = charbuff << 1;
	charbuff |= (signum == SIGUSR1);
	i++;
	if (i == 8)
		i = ft_put_message(&c, &client_pid, &charbuff);
	usleep(100);
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_signal_error();
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	ft_printf("minitalk server pid=%d\n", getpid());
	ft_memset(&act1, 0, sizeof(sigaction));
	ft_memset(&act2, 0, sizeof(sigaction));
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	sigemptyset(&act1.sa_mask);
	sigemptyset(&act2.sa_mask);
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act2.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q server");
// }