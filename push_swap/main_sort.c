/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:27:12 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 15:01:22 by csakamot         ###   ########.fr       */
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
		ft_threearg_sort(a_stack);
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

	a_start = a_stack;
	if (a_stack -> flag)
		a_stack = a_stack -> next;
	a_stack = a_stack -> next;
	if ((a_stack -> prev)-> content > a_stack -> content)
		ft_sort_rule_sa(a_start);
	return ;
}

void	ft_threearg_sort(t_node *a_stack)
{
	t_node	*a_start;

	a_start = a_stack;
	if (a_stack -> flag)
		a_stack = a_stack -> next;
	if (a_stack -> content < (a_stack -> next)-> content)
	{
		ft_small_head_sort(a_start, a_stack);
	}
	else
	{
		ft_big_head_sort(a_start, a_stack);
	}
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

	// for (int i = 0; i < 3; i++)
	// {
	// 	ft_printf("%d\n", a_start -> content);
	// 	a_start = a_start -> next;
	// }
