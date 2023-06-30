/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:48:07 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/30 17:02:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"



int	main(int argc, char **argv)
{
	return (0);
}

// void	ft_send_signal(int pid, unsigned char chare)
// {
// 	int				i;
// 	unsigned char	temp_char;

// 	i = 8;
// 	temp_char = chara;
// 	while (i > 0)
// 	{
// 		i--;
// 		temp_char = chara >> i;
// 		if (temp_char % 2 == 0)
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(42);
// 	}
// }