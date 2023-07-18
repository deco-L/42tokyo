/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:00:36 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/18 15:48:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_create_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, \
											WINDOW_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		exit(EXIT_FAILURE);
	}
}
