/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:32:03 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/25 16:59:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_w(t_game *game, t_img *texture, int x, int y)
{
	ft_printf("%d\n", ++game->walk_cnt);
	return ;
}

void	ft_move_a(t_game *game, t_img *texture, int x, int y)
{
	ft_printf("%d\n", ++game->walk_cnt);
	return ;
}

void	ft_move_s(t_game *game, t_img *texture, int x, int y)
{
	ft_printf("%d\n", ++game->walk_cnt);
	return ;
}

void	ft_move_d(t_game *game, t_img *texture, int x, int y)
{
	ft_printf("%d\n", ++game->walk_cnt);
	return ;
}
