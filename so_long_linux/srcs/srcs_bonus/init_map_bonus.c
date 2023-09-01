/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:51:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/02 04:13:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux_bonus.h"

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error_msg("Invalid number of argument.");
	if (ft_strrncmp(argv[1], ".ber", 4))
		ft_error_msg("The extension is not .ber");
	return ;
}

char	*ft_singl_col_input(int fd, char *line)
{
	size_t	i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		line = ft_strjoin_solong(line, str);
		i++;
	}
	ft_mapcheck_blank_line(line);
	return (line);
}

void	ft_input_map(int fd, t_game *game)
{
	char	*line;

	line = ft_calloc(1, 1);
	line = ft_singl_col_input(fd, line);
	game->map = ft_split(line, '\n');
	if (!game->map)
		ft_error_msg("Error\nMalloc failed.");
	free (line);
	return ;
}

void	ft_set_player(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game -> map[y] != NULL)
	{
		x = 0;
		while (game -> map[y][x] != '\0')
		{
			if (game -> map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
			}
			if (game -> x && game -> y)
				break ;
			x++;
		}
		if (game -> x && game -> y)
			break ;
		y++;
	}
	return ;
}

void	ft_init_map(int argc, char **argv, t_game *game)
{
	int	fd;

	ft_memset(game, 0, sizeof(t_game));
	ft_check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error_msg("Error\nFile not found.");
	ft_input_map(fd, game);
	ft_check_map(game);
	ft_set_player(game);
	close (fd);
	return ;
}

	// for (int i = 0; game -> map[i]; i++)
	// 	printf("%s\n", game -> map[i]);