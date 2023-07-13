/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:53:23 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/13 15:25:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minilibx_test_mac.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	color = create_trgb(0, 255, 0, 0);
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pixel_put(img, j++, i, color);
		render_rainbow_color(&color);
		i++;
	}
}

int	*render_rainbow_color(int *color)
{
	if (get_r(*color) == 0xFF && get_g(*color) != 0xFF && get_b(*color) == 0)
		*color += 0x00000100;
	else if (get_r(*color) != 0 && get_g(*color) == 0xFF && get_b(*color) == 0)
		*color -= 0x00010000;
	else if (get_r(*color) == 0 && get_g(*color) == 0xFF && \
											get_b(*color) != 0xFF)
		*color += 0x00000001;
	else if (get_r(*color) == 0 && get_g(*color) != 0 && get_b(*color) == 0xFF)
		*color -= 0x00000100;
	else if (get_r(*color) != 0xFF && get_g(*color) == 0 && \
											get_b(*color) == 0xFF)
		*color += 0x00010000;
	else if (get_r(*color) == 0xFF && get_g(*color) == 0 && get_b(*color) != 0)
		*color -= 0x00000001;
	return (*color);
}
