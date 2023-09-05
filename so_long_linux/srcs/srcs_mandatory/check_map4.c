/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:59:45 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/05 23:11:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long_linux.h"

void	ft_exit_path_search(t_game *game, size_t x, size_t y)
{
	if (!game->exit_path_flag)
	{
		if (game->map[y][x] == 'C')
			game->exit_path_flag++;
		if (game->map[y - 1][x] != '1' || game->map[y - 1][x] != 'E')
			ft_exit_path_search(game, x, y - 1);
		else if (game->map[y][x - 1] != '1' || game->map[y][x - 1] != 'E')
			ft_exit_path_search(game, x - 1, y);
		else if (game->map[y + 1][x] != '1' || game->map[y + 1][x] != 'E')
			ft_exit_path_search(game, x, y + 1);
		else if (game->map[y][x + 1] != '1' || game->map[y][x + 1] != 'E')
			ft_exit_path_search(game, x + 1, y);
	}
	return ;
}
