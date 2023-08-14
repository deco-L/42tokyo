/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:02:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/14 16:52:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_img(t_game *game, void	*img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void	ft_create_map(t_game *game, t_img *texture)
{
	int	width;
	int	height;

	height = 0;
	while (height < game -> map_h)
	{
		width = 0;
		while (width < game -> map_w)
		{
			if (game->map[height][width] == '0')
				ft_put_img(game, texture->floor, SIZE * width, SIZE * height);
			if (game->map[height][width] == '1')
				ft_put_img(game, texture->wall, SIZE * width, SIZE * height);
			if (game->map[height][width] == 'E')
				ft_put_img(game, texture->esc, SIZE * width, SIZE * height);
			if (game->map[height][width] == 'C')
				ft_put_img(game, texture->item, SIZE * width, SIZE * height);
			if (game->map[height][width] == 'P')
				ft_put_img(game, texture->player, SIZE * width, SIZE * height);
			width++;
		}
		height++;
	}
}
