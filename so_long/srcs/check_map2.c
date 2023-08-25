/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:15:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/25 16:11:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
					&& game->map[height][width] != '1'\
					&& game->map[height][width] != 'C' \
					&& game->map[height][width] != 'E' \
					&& game->map[height][width] != 'P')
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
	while (height < game->map_h)
	{
		width = 0;
		while (width < game->map_w)
		{
			if (game->map[height][width] == 'C')
				game->coin_cnt++;
			else if (game->map[height][width] == 'P')
				game->player_cnt++;
			else if (game->map[height][width] == 'E')
				game->exit_cnt++;
			width++;
		}
		height++;
	}
	if (!(game->coin_cnt && game->player_cnt && game->exit_cnt))
		ft_error_msg("Error\nMap does not contain required characters.");
	return ;
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
	printf("%d, %d\n", game->map_h, game->map_w);
	if (game->map_h > 32 || game->map_w > 60)
		ft_error_msg("Error\nMap is too large.");
	return ;
}
