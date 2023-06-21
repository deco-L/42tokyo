/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:57:10 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 16:22:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_input_arg(int argc, char **argv, int flag)
{
	int	*index_stack;
	int	*sort_stack;

	index_stack = ft_calloc(argc, sizeof(int));
	sort_stack = ft_calloc(argc, sizeof(int));
	if (flag)
		index_stack = ft_format_input(index_stack, argv);
	else
		index_stack = ft_input(index_stack, argc, argv);
	ft_sort_array(sort_stack, index_stack, argc - 1);
	free (index_stack);
	free (sort_stack);
}
