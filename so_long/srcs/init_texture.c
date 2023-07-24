/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:07:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/24 10:42:26 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_texture(t_game *game, t_img *texture)
{
	ft_memset(texture, 0, sizeof(t_img));
	texture->wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./texture/map/wall.xpm", &texture->wall_w, &texture->wall_h);
	texture->floor = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./texture/map/floor.xpm", &texture->floor_w, &texture->floor_h);
	texture->esc = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./texture/map/esc.xpm", &texture->esc_w, &texture->esc_h);
	texture->item = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./texture/map/item.xpm", &texture->item_w, &texture->item_h);
	texture->player = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./texture/player/p_idle_f.xpm", &texture->player_w, &texture->player_h);
	printf("%d, %d\n", texture->wall_w, texture->wall_h);
	printf("%d, %d\n", texture->floor_w, texture->floor_h);
	printf("%d, %d\n", texture->esc_w, texture->esc_h);
}
