/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:36 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/06 14:12:46 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_exit_path_search(t_game *game, size_t x, size_t y)
{
	if (!game->exit_path_flag)
	{
		if (game->map[y][x] == 'C')
		{
			game->exit_path_flag++;
			ft_return_path(game, x, y);
		}
		game->map[y][x]--;
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
			ft_exit_path_search(game, x, y - 1);
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
			ft_exit_path_search(game, x - 1, y);
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
			ft_exit_path_search(game, x, y + 1);
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
			ft_exit_path_search(game, x + 1, y);
		ft_return_path(game, x, y);
	}
	return ;
}
