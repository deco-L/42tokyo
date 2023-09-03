/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:50:40 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/03 12:51:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_closing_process(game);
	else if (keycode == KEY_W)
		ft_move_wasd(game, game->texture, game->x, game->y - 1);
	else if (keycode == KEY_A)
		ft_move_wasd(game, game->texture, game->x - 1, game->y);
	else if (keycode == KEY_S)
		ft_move_wasd(game, game->texture, game->x, game->y + 1);
	else if (keycode == KEY_D)
		ft_move_wasd(game, game->texture, game->x + 1, game->y);
	return (0);
}
