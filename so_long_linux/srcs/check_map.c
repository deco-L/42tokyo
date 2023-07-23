/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:57:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/23 16:52:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_check_map(t_game *game)
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
