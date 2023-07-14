/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:24:45 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 23:28:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_error_msg(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}
