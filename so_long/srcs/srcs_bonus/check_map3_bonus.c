/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:12:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/03 12:51:25 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
