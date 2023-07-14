/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_linux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:54:06 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 22:24:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LINUX_H
# define SO_LONG_LINUX_H

# include "../srcs/libft/printf/ft_printf.h"
# include "../srcs/libft/get_next_line/get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

/*
+++Window_Size+++
*/
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600

/*
+++Keycode+++
*/
# define ESC 65307

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}				t_game;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*
+++Windows_Related+++
*/

void	ft_create_window(t_game *data);
int		ft_closing_process(t_game *data);

/*
+++Keypress_Event+++
*/

int		ft_key_hook(int keycode, t_game *game);

#endif