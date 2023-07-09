/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:48:07 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/09 12:46:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_signal_error(void)
{
	ft_putstr_fd("Signal Error.\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_signal_error();
		}
		digit--;
		usleep(100);
	}
}

void	ft_check(const int signal)
{
	static int	bit;

	if (signal == SIGUSR1)
		ft_printf("Sucsess! Send %d signal.\n", ++bit);
	else if (signal == SIGUSR2)
		bit++;
	else
		ft_putstr_fd("No Relation!\n", STDOUT_FILENO);
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		ft_send_char(pid, *str);
		str++;
	}
	ft_send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("input ./client <server_pid> <text>\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) != 1)
		{
			ft_printf("input ./client <server_pid> <text>\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_check);
	signal(SIGUSR2, ft_check);
	send_str(pid, argv[2]);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q client");
// }