/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:57:20 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/19 17:30:43 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_map(t_game *game)
{
	size_t	row;
	size_t	cow;

	row = 0;
	while (game -> map[row])
	{
		cow = ft_strlen(game -> map[row]);
		if (0 < cow && cow < 4)
		{
			if ((cow == 1 && !ft_strchr(game -> map[row], '\n')) || cow != 1)
				ft_error_msg("Error\nCannot create map.\n");
			i++;
			continue ;
		}
		else
		{
			if (game -> map_w == 0)
				game -> map_w = cow;
			if (game -> map_w != cow && game -> map_w)
				ft_error_msg("Error\nCannot create map.\n");
			game -> map_h++;
		}
		i++;
	}
}
