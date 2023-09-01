/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:52:09 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/02 04:42:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux_bonus.h"

int	ft_loop_hook(t_game *game)
{
	static int	count;

	count++;
	while (count == 15000)
	{
		if (!game->pl_mode)
			game->pl_mode++;
		else
			game->pl_mode--;
		ft_run_anime(game, game->texture);
		count = 0;
	}
	return (0);
}

void	ft_run_anime(t_game *game, t_img *texture)
{
	int		nbr;
	size_t	width;
	size_t	height;

	nbr = rand();
	game->enemy_nbr = nbr % game->enemy_cnt;
	height = 0;
	while (height < game->map_h)
	{
		width = 0;
		while (width < game->map_w)
		{
			if (game->map[height][width] == 'P' && !game->pl_mode)
				ft_put_img(game, texture->player1, SIZE * width, SIZE * height);
			if (game->map[height][width] == 'P' && game->pl_mode)
				ft_put_img(game, texture->player2, SIZE * width, SIZE * height);
			if (game->map[height][width] == 'X')
				ft_roaming_enemy(game, nbr, width, height);
			width++;
		}
		height++;
	}
	return ;
}

void	ft_roaming_enemy(t_game *game, int nbr, size_t width, size_t height)
{
	int	directions;

	directions = nbr % 4;
	if (game->enemy_nbr == 0)
	{
		game->enemy_x = width;
		game->enemy_y = height;
		if (directions == 0 && game->map[height - 1][width] == '0')
			ft_move_enemy(game, game->texture, width, height - 1);
		else if (directions == 1 && game->map[height][width + 1] == '0')
			ft_move_enemy(game, game->texture, width + 1, height);
		else if (directions == 2 && game->map[height + 1][width] == '0')
			ft_move_enemy(game, game->texture, width, height + 1);
		else if (directions == 3 && game->map[height][width - 1] == '0')
			ft_move_enemy(game, game->texture, width - 1, height);
	}
	game->enemy_nbr--;
}

void	ft_move_enemy(t_game *game, t_img *texture, int x, int y)
{
	char	c;

	c = game->map[game->enemy_y][game->enemy_x];
	game->map[game->enemy_y][game->enemy_x] = game->map[y][x];
	game->map[y][x] = c;
	game->enemy_x = x;
	game->enemy_y = y;
	ft_create_map(game, texture);
}
