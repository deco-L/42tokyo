/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:27:12 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/24 15:54:51 by csakamot         ###   ########.fr       */
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
	else if (4 <= index && index <= 6)
		ft_fewargs_sort(a_stack, b_stack, index);
	else
		ft_args_sort(a_stack, b_stack, index);
	for (int i = 0; i < index + 1; i++)
	{
		printf("b_stack[%d] content : %d flag : %d point : %p prev : %p next : %p\n",\
		 i, b_stack -> content, b_stack -> flag, b_stack, b_stack -> prev, b_stack -> next);
		if (b_stack -> next == NULL)
			break ;
		b_stack = b_stack -> next;
	}
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
		ft_sort_rule_sab(a_start, 0);
}

void	ft_threearg_sort(t_node *a_stack)
{
	t_node	*a_start;

	a_start = a_stack;
	if (a_stack -> flag)
		a_stack = a_stack -> next;
	if (a_stack -> content < (a_stack -> next)-> content)
		ft_small_head_sort(a_start, a_stack);
	else
		ft_big_head_sort(a_start, a_stack);
	return ;
}

void	ft_fewargs_sort(t_node *a_stack, t_node *b_stack, int index)
{
	int		i;
	t_node	*a_start;
	t_node	*b_start;

	i = 0;
	a_start = a_stack;
	b_start = b_stack;
	if (ft_sort_checker(a_start))
		return ;
	ft_fewsort_push(a_start, b_start, index);
	ft_threearg_sort(a_start);
	if (index == 6)
		ft_threearg_resort(b_start);
	else if (index == 5)
		ft_twoarg_resort(b_start);
	while (i < index - 3)
	{
		ft_sort_rule_pab(b_stack, a_stack, 0);
		i++;
	}
	return ;
}

void	ft_args_sort(t_node *a_stack, t_node *b_stack, int index)
{
	int	pivot;
	int	group;

	if (ft_sort_checker(a_stack))
		return ;
	pivot = index / 100 * 3 + 7;
	group = index / pivot;
	ft_argsort_push(a_stack, b_stack, pivot, group);
}
