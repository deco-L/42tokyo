/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input_error_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:40:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/22 11:51:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_arg_less(void)
{
	ft_putstr("Please enter arguments.\n");
	exit(EXIT_FAILURE);
}

int	ft_one_arg_check(char **argv)
{
	int			flag;
	long long	i;

	i = 0;
	flag = 0;
	while (argv[1][i] != '\0')
	{
		if (!(ft_isdigit(argv[1][i]) || (argv[1][i] == ' ')))
		{
			ft_putstr("Invalid argument.\n");
			exit(EXIT_FAILURE);
		}
		if (argv[1][i] == ' ')
			flag++;
		i++;
	}
	return (flag);
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
				ft_putstr("Invalid argument.\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
