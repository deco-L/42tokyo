/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:17:56 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 20:41:58 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_malloc_error(void)
{
	ft_printf("Malloc failed.\n");
	exit(EXIT_FAILURE);
}

void	ft_mallocerror_node(t_node *a_stack, int i)
{
	ft_printf("Malloc failed.\n");
}