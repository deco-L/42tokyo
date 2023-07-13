/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:45:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/13 15:10:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minilibx_test_mac.h"

int	render_circle(t_data *data, t_img *img)
{
	create_circle(img, (t_circle){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 100, BLUE_PIXEL});
	return (0);
}

void	create_circle(t_img *img, t_circle circle)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = circle.y - circle.r;
	while (i < circle.y + circle.r)
	{
		j = circle.x - circle.r;
		while (j < circle.x + circle.r)
		{
			dy = j - circle.x;
			dx = i - circle.y;
			if ((dx * dx) + (dy * dy) <= circle.r * circle.r)
				my_mlx_pixel_put(img, j, i, circle.color);
			j++;
		}
		i++;
	}
}
