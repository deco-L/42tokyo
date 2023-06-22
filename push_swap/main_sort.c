/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:27:12 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 12:25:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_main_sort(t_node *a_stack, int index)
{
	t_node	*b_stack;

	b_stack = ft_mkloop_node(&b_stack, NULL, 0);
	if (index == 1)
	{
		free(b_stack);
		return ;
	}
	else if (index == 2)
		ft_twoarg_sort(a_stack);
	else if (index == 3)
		ft_threearg_sort(a_stack, b_stack);
	else if (4 <= index || index <= 6)
		ft_fewargs_sort(a_stack, b_stack, index);
	else
		ft_args_sort(a_stack, b_stack, index);
	ft_delete_all_node(b_stack);
	return ;
}

void	ft_twoarg_sort(t_node *a_stack)
{
	t_node	*a_start;

	a_stack = a_stack -> next;
	a_start = a_stack;
	a_stack = a_stack -> next;
	if (a_start -> content > a_stack -> content)
		ft_putstr("sa\n");
	return ;
}

void	ft_threearg_sort(t_node *a_stack, t_node *b_stack)
{
	return ;
}

void	ft_fewargs_sort(t_node *a_stack, t_node *b_stack, int index)
{
	return ;
}

void	ft_args_sort(t_node *a_stack, t_node *b_stack, int index)
{
	return ;
}
