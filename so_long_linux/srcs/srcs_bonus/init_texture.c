/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:07:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/31 17:40:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux.h"

void	ft_init_texture(t_game *game, t_img *texture)
{
	ft_memset(texture, 0, sizeof(t_img));
	texture->wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		WALL, &texture->wall_w, &texture->wall_h);
	texture->floor = mlx_xpm_file_to_image(game->mlx_ptr, \
		FLOOR, &texture->floor_w, &texture->floor_h);
	texture->esc = mlx_xpm_file_to_image(game->mlx_ptr, \
		ESCAPE, &texture->esc_w, &texture->esc_h);
	texture->item = mlx_xpm_file_to_image(game->mlx_ptr, \
		ITEM, &texture->item_w, &texture->item_h);
	texture->player = mlx_xpm_file_to_image(game->mlx_ptr, \
	PLAYER, &texture->player_w, &texture->player_h);
	game->texture = texture;
}

	// printf("%d, %d\n", texture->wall_w, texture->wall_h);
	// printf("%d, %d\n", texture->floor_w, texture->floor_h);
	// printf("%d, %d\n", texture->esc_w, texture->esc_h);
	// printf("%d, %d\n", texture->item_w, texture->item_h);
	// printf("%d, %d\n", texture->player_w, texture->player_h);