/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:19:28 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/20 20:38:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_input_arg_error(int argc, char **argv)
{
	if (argc <= 1)
		ft_arg_less();
	else if (argc == 2)
		ft_one_arg_check(argv);
	else
		ft_args_check(argc, argv);
}
