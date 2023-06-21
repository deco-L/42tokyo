/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arg_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:52:40 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 17:16:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	*ft_input(int *index_stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		index_stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (index_stack);
}

int	*ft_format_input(int *index_stack, char **argv)
{
	return (NULL);
}

int	*ft_sort_array(int *sort_stack, int *index_stack, int index)
{
	int	i;
	int	j;
	int	buff;
	int	*result;

	i = 0;
	j = 0;
	buff = 0;
	sort_stack = ft_int_cpy(sort_stack, index_stack, index);
	while (i < index)
	{
		j = 0;
		while (j < index - (1 + i))
		{
			if (sort_stack[j] > sort_stack[j + 1])
			{
				buff = sort_stack[j];
				sort_stack[j] = sort_stack[j + 1];
				sort_stack[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
	return (sort_stack);
}

int	*ft_int_cpy(int *dest, const int *src, int n)
{
	int	i;
	int	*result;
	int	*origin;

	i = 0;
	result = dest;
	origin = (int *)src;
	while (i < n)
	{
		result[i] = src[i];
		i++;
	}
	return (result);
}

int	*ft_cc(int *ccstack, int *sort_stack, int index)
{
	int	i;
	int	j;
	int	*result;
	int	*src;

	i = 0;
	j = 0;
	result = ccstack;
	src = sort_stack;
	while (i < index)
	{
		j = 0;
		while (j < index)
		{
			if (result[i] == sort_stack[j])
				result[i] = j;
			j++;
		}
		i++;
	}
	return (result);
}
