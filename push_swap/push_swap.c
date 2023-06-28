/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:09:40 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/28 17:14:50 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		flag;
	int		index;
	char	**relay;
	t_node	*a_stack;

	flag = 0;
	relay = NULL;
	a_stack = NULL;
	flag = ft_standard_input_error(argc, argv);
	if (flag)
	{
		ft_format_error(argv);
		index = ft_format_input(argv[1], relay);
		ft_printf("%s\n", relay[1]);
		a_stack = ft_input_arg(index, relay, a_stack);
		free(relay);
	}
	a_stack = ft_input_arg(argc - 1, argv, a_stack);
	ft_main_sort(a_stack, argc - 1);
	// ft_printf("ok!\n");
	// for (int i = 0; i < argc; i++)
	// {
	// 	printf("a_stack[%d] content : %d flag : %d point : %p prev : %p next : %p\n",\
	// 	 i, a_stack -> content, a_stack -> flag, a_stack, a_stack -> prev, a_stack -> next);
	// 	a_stack = a_stack -> next;
	// }
	ft_delete_all_node(a_stack);
	return (0);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
// compaction of coordinates
