/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 12:33:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data	data;
	t_img	img;

	ft_create_window(&data);
	mlx_hook(data.win_ptr, 17, 1L << 2, ft_closing_process, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q solong");
}