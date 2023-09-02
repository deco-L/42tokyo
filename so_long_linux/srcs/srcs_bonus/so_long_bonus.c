/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/02 18:07:34 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux_bonus.h"

void	ft_mlx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
}

int	ft_display_on(t_game *game)
{
	ft_create_map(game, game->texture, NO_CNT);
	return (0);
}

void	ft_hook_list(t_game *game)
{
	mlx_key_hook(game->win_ptr, ft_key_hook, game);
	mlx_hook(game->win_ptr, 17, 1L << 2, ft_closing_process, game);
	mlx_expose_hook(game->win_ptr, ft_display_on, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	texture;

	ft_init_map(argc, argv, &game);
	ft_mlx_init(&game);
	ft_init_texture(&game, &texture);
	ft_create_window(&game, &texture);
	ft_hook_list(&game);
	mlx_loop_hook(game.mlx_ptr, ft_loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q solong");
// }