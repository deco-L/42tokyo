/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:12:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/07 15:28:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_mapcheck_wall_less(t_game *game)
{
	int		flag;
	size_t	i;
	size_t	j;

	flag = 0;
	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (i == 0 || i == game->map_h - 1)
				flag += game->map[i][j] - '1';
			else if (j == 0 || j == game->map_w - 1)
				flag += game->map[i][j] - '1';
			if (flag)
				ft_error_msg("Error\nThis map is not walled off.");
			j++;
		}
		i++;
	}
	return ;
}

void	ft_mapcheck_path(t_game *game)
{
	size_t	coin_tmp;

	coin_tmp = game->coin_cnt;
	ft_coin_path_search(game, 0, game->x, game->y);
	game->coin_cnt = coin_tmp;
	ft_return_map(game);
	if (!game->coin_path_flag)
		ft_error_msg("Error\nThere is no path to the goal on this map.");
	ft_exit_path_search(game, game->exit_x, game->exit_y);
	if (!game->exit_path_flag)
		ft_error_msg("Error\nThere is no path to the goal on this map.");
	ft_return_map(game);
	return ;
}

void	ft_set_start_end(t_game *game, size_t x, size_t y)
{
	if (game->map[y][x] == 'P')
	{
		game->x = x;
		game->y = y;
		game->player_cnt++;
	}
	else if (game->map[y][x] == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
		game->exit_cnt++;
	}
	return ;
}

void	ft_coin_path_search(t_game *game, size_t count, size_t x, size_t y)
{
	if (!game->coin_path_flag)
	{
		if (game->map[y][x] == 'C')
			game->coin_cnt--;
		if (!game->coin_cnt)
			game->coin_path_flag++;
		game->map[y][x]--;
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
			ft_coin_path_search(game, count, x, y - 1);
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
			ft_coin_path_search(game, count, x - 1, y);
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
			ft_coin_path_search(game, count, x, y + 1);
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
			ft_coin_path_search(game, count, x + 1, y);
	}
}
