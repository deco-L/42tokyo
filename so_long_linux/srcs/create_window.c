/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:00:36 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/10 19:44:04 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_create_window(t_game *game, t_img *texture)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, SIZE * game->map_w, \
											SIZE * game->map_h, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		exit(EXIT_FAILURE);
	}
	ft_create_map(game, texture);
}
