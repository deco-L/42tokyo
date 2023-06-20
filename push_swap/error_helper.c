/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:40:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/20 13:52:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_arg_less(void)
{
	ft_printf("Please enter arguments.");
	return (1);
}

int	ft_one_arg_check(char **argv)
{
	long long	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Invalid argument.");
			return (1);
		}
		i++;
	}
	return (1);
}

int	ft_args_check(int argc, char **argv)
{
	int			i;
	long long	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Invalid argument");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
