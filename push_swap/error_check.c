/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:19:28 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/20 13:47:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// int	ft_input_arg_error(int argc, char **argv)
// {
// 	int			j;
// 	long long	i;

// 	i = 1;
// 	if (argc <= 1)
// 	{
// 		input_less();
// 		return (1);
// 	}
// 	while (i < argc)
// 	{
// 		j = 0;
// 		while (argv[i][j] != '\0')
// 		{
// 			if (!ft_isdigit(argv[i][j]))
// 			{
// 				ft_invalid_arg();
// 				return (1);
// 			}
// 			if (argc == 2)
// 				return (1);
// 				j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	ft_input_arg_error(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc <= 1)
		flag = ft_arg_less();
	else if (argc == 2)
		flag = ft_one_arg_check(argv);
	else
		flag = ft_args_check(argc, argv);
	return (flag);
}
