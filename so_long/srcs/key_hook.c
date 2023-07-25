/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:50:40 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/25 16:59:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_closing_process(game);
	else if (keycode == KEY_W)
		ft_move_w(game, game->texture, game->x, game->y);
	else if (keycode == KEY_A)
		ft_move_a(game, game->texture, game->x, game->y);
	else if (keycode == KEY_S)
		ft_move_s(game, game->texture, game->x, game->y);
	else if (keycode == KEY_D)
		ft_move_d(game, game->texture, game->x, game->y);
	return (0);
}
