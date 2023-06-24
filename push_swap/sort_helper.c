/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:52:02 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/24 15:21:33 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_sort_checker(t_node *stack)
{
	stack = stack -> next;
	while (!(stack -> flag))
	{
		if ((stack -> prev)-> content > stack -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
