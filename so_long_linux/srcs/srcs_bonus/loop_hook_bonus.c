/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:52:09 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/02 00:10:14 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux_bonus.h"

int	ft_loop_hook(t_game *game)
{
	static int	count;

	count++;
	while (count == 5000)
	{
		if (!game->pl_mode)
			game->pl_mode++;
		else
			game->pl_mode--;
		ft_run_anime(game, game->texture);
		count = 0;
	}
	return (0);
}

void	ft_run_anime(t_game *game, t_img *texture)
{
	size_t	width;
	size_t	height;

	height = 0;
	while (height < game->map_h)
	{
		width = 0;
		while (width < game->map_w)
		{
			if (game->map[height][width] == 'P' && !game->pl_mode)
				ft_put_img(game, texture->player1, SIZE * width, SIZE * height);
			if (game->map[height][width] == 'P' && game->pl_mode)
				ft_put_img(game, texture->player2, SIZE * width, SIZE * height);
			width++;
		}
		height++;
	}
	return ;
}