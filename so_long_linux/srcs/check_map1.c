/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:57:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/11 19:14:10 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_mapcheck_blank_line(char *line)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n')
			break ;
		i++;
	}
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			flag++;
		if (line[i] != '\n' && flag == 1)
			flag = 0;
		else if (line[i] != '\n' && flag > 1)
			ft_error_msg("Error\nThe map contains an blank line.");
		i++;
	}
	return ;
}

void	ft_mapcheck_matrix(t_game *game)
{
	size_t	row;
	size_t	cow;

	row = 0;
	while (game -> map[row])
	{
		cow = ft_strlen(game -> map[row]);
		if (0 < cow && cow < 3)
			ft_error_msg("Error\nInvalid map.");
		else
		{
			if (game -> map_w == 0)
				game -> map_w = cow;
			if (game -> map_w != cow && game -> map_w)
				ft_error_msg("Error\nInvalid map.");
			game -> map_h++;
		}
		row++;
	}
	if (0 < row && row < 3)
		ft_error_msg("Error\nInvalid map.");
}

void	ft_mapcheck_character(t_game *game)
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
			else if (game->map[height][width] == 'C')
				game->coin_cnt++;
			width++;
		}
		height++;
	}
}

void	ft_mapcheck_rectangle(t_game *game)
{
	if (game -> map_h == game -> map_w)
		ft_error_msg("Error\nThe map is not rectangular.\n");
	return ;
}

void	ft_check_map(t_game *game)
{
	ft_mapcheck_empty(game);
	ft_mapcheck_matrix(game);
	ft_mapcheck_character(game);
	ft_mapcheck_rectangle(game);
}
