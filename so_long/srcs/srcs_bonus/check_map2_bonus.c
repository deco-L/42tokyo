/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:15:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/05 02:50:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_mapcheck_empty(t_game *game)
{
	if (game -> map[0] == NULL)
		ft_error_msg("Error\nEmpty map.");
	return ;
}

void	ft_mapcheck_invalid_ch(t_game *game)
{
	size_t	width;
	size_t	height;

	height = 0;
	while (height < game->map_h)
	{
		width = 0;
		while (width < game->map_w)
		{
			if (game->map[height][width] != '0' \
					&& game->map[height][width] != '1' \
					&& game->map[height][width] != 'C' \
					&& game->map[height][width] != 'E' \
					&& game->map[height][width] != 'P' \
					&& game->map[height][width] != 'X')
				ft_error_msg("Error\nMap contains invalid characters.");
			width++;
		}
		height++;
	}
}

void	ft_mapcheck_required_ch(t_game *game)
{
	size_t	width;
	size_t	height;

	height = 0;
	while (height++ < game->map_h)
	{
		width = 0;
		while (width++ < game->map_w)
		{
			if (game->map[height - 1][width - 1] == 'C')
				game->coin_cnt++;
			else if (game->map[height - 1][width - 1] == 'X')
				game->enemy_cnt++;
			else if (game->map[height - 1][width - 1] == 'P')
			{
				game->x = width - 1;
				game->y = height - 1;
				game->player_cnt++;
			}
			else if (game->map[height - 1][width - 1] == 'E')
				game->exit_cnt++;
		}
	}
	if (!(game->coin_cnt && game->player_cnt && game->exit_cnt))
		ft_error_msg("Error\nMap does not contain required characters.");
}

void	ft_mapcheck_duplicates_ch(t_game *game)
{
	if (game->player_cnt != 1 && game->exit_cnt != 1)
		ft_error_msg("Error\nPlayer and Exits are duplicated.");
	if (game->player_cnt != 1)
		ft_error_msg("Error\nPlayer is duplicated.");
	else if (game->exit_cnt != 1)
		ft_error_msg("Error\nExits are duplicated.");
	return ;
}

void	ft_mapcheck_large_map(t_game *game)
{
	if (game->map_h > WINDOW_HEIGHT / 32 - 2 || game->map_w > WINDOW_WIDTH / 32)
		ft_error_msg("Error\nMap is too large.");
	return ;
}

	// printf("%ld, %ld\n", game->map_h, game->map_w);