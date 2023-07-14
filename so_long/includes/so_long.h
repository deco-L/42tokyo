/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:54:06 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 13:10:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "../srcs/libft/printf/ft_printf.h"
# include "../srcs/libft/get_next_line/get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
}				t_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*
+++Windows_related+++
*/

void	ft_create_window(t_data *data);
int		ft_closing_process(t_data *data);

#endif