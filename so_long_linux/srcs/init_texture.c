/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:07:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/23 18:38:25 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_init_texture(t_game *game, t_img *texture)
{
	ft_memset(texture, 0, sizeof(t_img));
	texture->floor = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./texture/map/FotoJet.xpm", &texture->floor_w, &texture->floor_h);
}
