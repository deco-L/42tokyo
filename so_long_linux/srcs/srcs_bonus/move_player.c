/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:32:03 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/31 17:40:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux.h"

void	ft_move_player(t_game *game, t_img *texture, int x, int y)
{
	char	c;

	c = game->map[game->y][game->x];
	game->map[game->y][game->x] = game->map[y][x];
	game->map[y][x] = c;
	game->x = x;
	game->y = y;
	ft_create_map(game, texture);
	ft_printf("Count of movements: %d\n", ++game->walk_cnt);
}

void	ft_move_wasd(t_game *game, t_img *texture, int x, int y)
{
	if (game->map[y][x] == '0')
		ft_move_player(game, texture, x, y);
	else if (game->map[y][x] == 'C')
	{
		game->coin_flag++;
		game->map[y][x] = '0';
		ft_move_player(game, texture, x, y);
	}
	else if (game->map[y][x] == 'E' && game->coin_flag == game->coin_cnt)
	{
		game->map[y][x] = '0';
		ft_move_player(game, texture, x, y);
		ft_closing_process(game);
	}
	return ;
}

// void	ft_move_w(t_game *game, t_img *texture, int x, int y)
// {
// 	if (game->map[y - 1][x] == '0')
// 		ft_move_player(game, texture, x, y - 1);
// 	else if (game->map[y - 1][x] == 'C')
// 	{
// 		game->coin_flag++;
// 		game->map[y - 1][x] = '0';
// 		ft_move_player(game, texture, x, y - 1);
// 	}
// 	else if (game->map[y - 1][x] == 'E' && game->coin_flag == game->coin_cnt)
// 	{
// 		game->map[y - 1][x] = '0';
// 		ft_move_player(game, texture, x, y - 1);
// 		ft_closing_process(game);
// 	}
// 	return ;
// }

// void	ft_move_a(t_game *game, t_img *texture, int x, int y)
// {
// 	if (game->map[y][x - 1] == '0')
// 		ft_move_player(game, texture, x - 1, y);
// 	else if (game->map[y][x - 1] == 'C')
// 	{
// 		game->coin_flag++;
// 		game->map[y][x - 1] = '0';
// 		ft_move_player(game, texture, x - 1, y);
// 	}
// 	else if (game->map[y][x - 1] == 'E' && game->coin_flag == game->coin_cnt)
// 	{
// 		game->map[y][x - 1] = '0';
// 		ft_move_player(game, texture, x - 1, y);
// 		ft_closing_process(game);
// 	}
// 	return ;
// }

// void	ft_move_s(t_game *game, t_img *texture, int x, int y)
// {
// 	if (game->map[y + 1][x] == '0')
// 		ft_move_player(game, texture, x, y + 1);
// 	else if (game->map[y + 1][x] == 'C')
// 	{
// 		game->coin_flag++;
// 		game->map[y + 1][x] = '0';
// 		ft_move_player(game, texture, x, y + 1);
// 	}
// 	else if (game->map[y + 1][x] == 'E' && game->coin_flag == game->coin_cnt)
// 	{
// 		game->map[y + 1][x] = '0';
// 		ft_move_player(game, texture, x, y + 1);
// 		ft_closing_process(game);
// 	}
// 	return ;
// }

// void	ft_move_d(t_game *game, t_img *texture, int x, int y)
// {
// 	if (game->map[y][x + 1] == '0')
// 		ft_move_player(game, texture, x + 1, y);
// 	else if (game->map[y][x + 1] == 'C')
// 	{
// 		game->coin_flag++;
// 		game->map[y][x + 1] = '0';
// 		ft_move_player(game, texture, x + 1, y);
// 	}
// 	else if (game->map[y][x + 1] == 'E' && game->coin_flag == game->coin_cnt)
// 	{
// 		game->map[y][x + 1] = '0';
// 		ft_move_player(game, texture, x + 1, y);
// 		ft_closing_process(game);
// 	}
// 	return ;
// }