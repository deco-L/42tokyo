/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:17:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/04 12:26:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_test.h"

void	handler1(int signal)
{
	exit(EXIT_SUCCESS);
}

void	handler2(int signal)
{
	write(STDERR_FILENO, ".", 1);
	alarm(5);
}

int	main(void)
{
	signal(SIGINT, handler1);
	signal(SIGALRM, handler2);
	alarm(5);

	while (1)
	{
	}

	return (0);
}
