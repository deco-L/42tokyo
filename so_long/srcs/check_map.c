/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:57:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/27 14:23:33 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_matrix(t_game *game)
{
	size_t	row;
	size_t	cow;

	row = 0;
	while (game -> map[row])
	{
		cow = ft_strlen(game -> map[row]);
		if (0 < cow && cow < 4)
			ft_error_msg("Error\nCannot create map.\n");
		else
		{
			if (game -> map_w == 0)
				game -> map_w = cow;
			if (game -> map_w != cow && game -> map_w)
				ft_error_msg("Error\nCannot create map.\n");
			game -> map_h++;
		}
		row++;
	}
}

void	ft_check_character(t_game *game)
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
				ft_error_msg("Error\nInvalid argument.");
			else if (game->map[height][width] == 'C')
				game->coin_cnt++;
			width++;
		}
		height++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_matrix(game);
	ft_check_character(game);
}
