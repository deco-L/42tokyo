/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 18:09:02 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_init	state;

	init_minishell(&state);
	signal_minishell(state.signal->action);
	standby_state(&state);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	execve("/bin/ls", argv, NULL);
// 	// printf("errno:%d\n", errno);
// 	// perror("fork");
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q minishell");
// }
