/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:19:28 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/21 15:06:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_standard_input_error(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc <= 1)
		ft_arg_less();
	else if (argc == 2)
		flag = ft_one_arg_check(argv);
	else
		ft_args_check(argc, argv);
	return (flag);
}
