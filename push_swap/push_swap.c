/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:09:40 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/23 20:58:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		flag;
	t_node	*a_stack;

	flag = 0;
	flag = ft_standard_input_error(argc, argv);
	a_stack = ft_input_arg(argc - 1, argv, a_stack, flag);
	ft_main_sort(a_stack, argc - 1);
	ft_printf("ok!\n");
	for (int i = 0; i < argc; i++)
	{
		printf("a_stack[%d] content : %d flag : %d point : %p prev : %p next : %p\n",\
		 i, a_stack -> content, a_stack -> flag, a_stack, a_stack -> prev, a_stack -> next);
		a_stack = a_stack -> next;
	}
	ft_delete_all_node(a_stack);
	ft_printf("aaa2");
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
// compaction of coordinates
