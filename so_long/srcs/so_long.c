/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/18 15:51:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_display_on(void)
{
	printf("on!\n");
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

	ft_init_map(argc, argv, &game, &texture);
	ft_create_window(&game);
	ft_hook_list(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q solong");
}