/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argssort_push_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:48:08 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/30 15:42:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_pushcheck_head(int check, int index, int group)
{
	int	head;
	int	margin;

	head = (index / group) * group;
	margin = 0;
	if (index - head >= group / 2)
	{
		margin = group / 2;
	}
	if (0 < check && check <= head + group + margin)
		return (1);
	return (0);
}

int	ft_pushcheck_tail(int check, int center, int index, int group)
{
	int	margin;

	margin = 0;
	if (index - (index / group) * group)
	{
		margin = group / 2;
	}
	if (center < check && check <= center + group)
		return (1);
	return (0);
}
