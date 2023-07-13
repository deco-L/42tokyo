/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/13 14:48:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minilibx_test_mac.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	press_key_event(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
		exit(EXIT_SUCCESS);
	}
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_data	data;
	t_img	img;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, \
									WINDOW_HEIGHT, "Hello world!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	render_background(&img, create_trgb(0, 255, 255, 255));
	render_rect(&data, &img);
	render_circle(&data, &img);
	my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);
	mlx_hook(data.win_ptr, 2, 1L << 0, press_key_event, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q test");
}
