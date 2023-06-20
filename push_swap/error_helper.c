/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:40:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/20 20:37:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_arg_less(void)
{
	ft_printf("Please enter arguments.");
	exit(EXIT_SUCCESS);
}

void	ft_one_arg_check(char **argv)
{
	long long	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Invalid argument.");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	ft_args_check(int argc, char **argv)
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
				exit(EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
}
