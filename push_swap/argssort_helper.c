/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argssort_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:49:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/24 19:15:51 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_argsort_push(t_node *a_stack, t_node *b_stack, int pivot, int group)
{
	int	i;
	int	j;
	int	check;
	int	center;

	i = 0;
	j = 0;
	while (a_stack -> next != a_stack)
	{
		center = (pivot / 2 + j / group + 1) * group;
		check = (a_stack -> next)-> content;
		if ((i / group) * group < check && check <= (i / group + 1) * group)
		{
			i++;
			ft_sort_rule_pab(a_stack, b_stack, 1);
		}
		else if (center < check && check <= center + group)
		{
			j++;
			ft_sort_rule_pab(a_stack, b_stack, 1);
			ft_sort_rule_rab(b_stack, 1);
		}
		else
			ft_sort_rule_rab(a_stack, 0);
	}
}
