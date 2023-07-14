/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:51:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 23:44:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error_msg("Invalid number of argument.");
	if (ft_strrncmp(argv[1], ".ber", 4))
		ft_error_msg("Invalid argument.");
	return ;
}

void	ft_input_map(int fd, t_game *game)
{
	return ;
}

void	ft_init_map(int argc, char **argv, t_game *game, t_img *texture)
{
	int	fd;

	ft_check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error_msg("File not found.");
	ft_input_map(fd, game);
	return ;
}
