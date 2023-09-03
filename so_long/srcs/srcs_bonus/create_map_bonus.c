/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:02:15 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/03 12:51:25 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_put_img(t_game *game, void	*img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void	ft_create_map(t_game *game, t_img *texture, int cnt)
{
	size_t	width;
	size_t	height;

	height = 0;
	while (height < game -> map_h)
	{
		width = 0;
		while (width < game -> map_w)
		{
			ft_render_map(game, texture, width, height);
			width++;
		}
		height++;
	}
	ft_put_walkcnt(game, game->texture, cnt);
}

void	ft_render_map(t_game *game, t_img *texture, size_t width, size_t height)
{
	if (game->map[height][width] == '0')
		ft_put_img(game, texture->floor, SIZE * width, SIZE * height);
	if (game->map[height][width] == '1')
		ft_put_img(game, texture->wall, SIZE * width, SIZE * height);
	if (game->map[height][width] == 'E')
		ft_put_img(game, texture->esc, SIZE * width, SIZE * height);
	if (game->map[height][width] == 'C')
		ft_put_img(game, texture->item, SIZE * width, SIZE * height);
	if (game->map[height][width] == 'P' && !game->pl_mode)
		ft_put_img(game, texture->player1, SIZE * width, SIZE * height);
	if (game->map[height][width] == 'P' && game->pl_mode)
		ft_put_img(game, texture->player2, SIZE * width, SIZE * height);
	if (game->map[height][width] == 'X')
		ft_put_img(game, texture->enemy, SIZE * width, SIZE * height);
}

void	ft_put_walkcnt(t_game *game, t_img *texture, int cnt)
{
	size_t	width;

	width = 0;
	while (width < game->map_w * 2)
	{
		ft_put_img(game, texture->back, BACK_SIZE * width, game->map_h * SIZE);
		width++;
	}
	game->walk_cnt_display = ft_itoa(game->walk_cnt);
	if (!game->walk_cnt_display)
		ft_error_msg("Error\nMallo failed.");
	mlx_string_put(game->mlx_ptr, game->win_ptr, \
					0, game->map_h * SIZE + 10, 0xFF0000, "walk count :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, \
				100, game->map_h * SIZE + 10, 0xFF0000, game->walk_cnt_display);
	if (cnt == CNT)
		game->walk_cnt++;
	free(game->walk_cnt_display);
}
