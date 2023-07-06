/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:48:07 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/06 15:46:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(150);
	}
}

void	ft_check(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("sucsess!\n", STDOUT_FILENO);
	else
		ft_putstr_fd("No relation!\n", STDOUT_FILENO);
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		signal(SIGUSR1, ft_check);
		signal(SIGUSR2, ft_check);
		ft_send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q client");
// }