/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input_error_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:40:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/28 17:08:43 by csakamot         ###   ########.fr       */
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
	if ((argv[1][i] == '-' || argv[1][i] == '+') && argv[1][i + 1] != '\0')
		i++;
	while (argv[1][i] != '\0')
	{
		if ((9 <= argv[1][i] && argv[1][i] <= 13) || argv[1][i] == ' ')
		{
			flag++;
			return (flag);
		}
		else if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr("Invalid argument.\n");
			exit(EXIT_FAILURE);
		}
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
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1] != '\0')
			j++;
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

void	ft_format_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] == '-' || argv[1][i] == '+') && argv[1][i + 1] != '\0')
			i++;
		else if (ft_isdigit(argv[1][i]))
			i++;
		else if ((9 <= argv[1][i] && argv[1][i] <= 13) || argv[1][i] == ' ')
			i++;
		else
		{
			ft_putstr("Invalid error.");
			exit(EXIT_FAILURE);
		}
	}
}
