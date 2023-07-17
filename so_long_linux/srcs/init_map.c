/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:51:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/17 20:16:12 by csakamot         ###   ########.fr       */
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
	return (line);
}

void	ft_input_map(int fd, t_game *game)
{
	char	*line;

	line = ft_calloc(1, 1);
	line = ft_singl_col_input(fd, line);
	game -> map = ft_split(line, '\n');
	free (line);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", game -> map[i]);
		free(game -> map[i]);
	}
	free (game -> map);
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
	close (fd);
	return ;
}
