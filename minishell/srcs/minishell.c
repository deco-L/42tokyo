/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/14 13:46:53 by csakamot         ###   ########.fr       */
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
// 	const char	*env;

// 	env = getenv("HTTPS_PROXY");
// 	printf("%s\n", env);
// 	// errno = execve("", argv, NULL);
// 	// printf("errno:%d\n", errno);
// 	perror("fork");
// 	return (0);
// }

__attribute__((destructor))
static void destructor() {
    system("leaks -q minishell");
}
