/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input_error_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:40:51 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/01 17:50:21 by csakamot         ###   ########.fr       */
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
	if (argv[1][0] == '\0')
		ft_invalid_arg();
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
			ft_invalid_arg();
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
		if (argv[i][0] == '\0')
			ft_invalid_arg();
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1] != '\0')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				ft_invalid_arg();
			j++;
		}
		i++;
	}
}

void	ft_format_error(char **argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] == '-' || argv[1][i] == '+') \
		&& ft_isdigit(argv[1][i + 1]))
			i++;
		else if (ft_isdigit(argv[1][i]))
		{
			flag++;
			i++;
		}
		else if ((9 <= argv[1][i] && argv[1][i] <= 13) || argv[1][i] == ' ')
			i++;
		else
			ft_invalid_arg();
	}
	if (flag)
		return ;
	ft_putstr("Invalid argument.\n");
	exit (EXIT_FAILURE);
}

void	ft_invalid_arg(void)
{
	ft_putstr("Invalid argument.\n");
	exit (EXIT_FAILURE);
	return ;
}
