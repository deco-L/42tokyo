/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:02:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/24 12:29:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_create_map(t_game *game, t_img *texture)
{
	int	width;
	int	height;

	height = 0;
	while (height++ < game -> map_h)
	{
		width = 0;
		while (width++ < game -> map_w)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		texture->floor, SIZE * width, SIZE * height);
			if (game->map[height - 1][width - 1] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		texture->wall, SIZE * width, SIZE * height);
			if (game->map[height - 1][width - 1] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		texture->esc, SIZE * width, SIZE * height);
			if (game->map[height - 1][width - 1] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		texture->item, SIZE * width, SIZE * height);
			if (game->map[height - 1][width - 1] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		texture->player, SIZE * width, SIZE * height);
		}
	}
}
