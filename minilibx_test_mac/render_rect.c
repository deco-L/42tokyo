/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:19:32 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/12 14:36:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minilibx_test_mac.h"

int	render_rect(t_data *data, t_img *img)
{
	create_rect(img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, \
													100, 100, GREEN_PIXEL});
	create_rect(img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	return (0);
}

int	create_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}
