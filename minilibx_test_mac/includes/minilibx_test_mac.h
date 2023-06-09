/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_test_mac.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:54:06 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/13 16:18:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_TEST_MAC_H
# define MINILIBX_TEST_MAC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define ESC 65307
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 900
# define MLX_ERROR 1
# define WHITE_PIXEL 0x00FFFFFF
# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define BLUE_PIXEL 0x000000FF

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

typedef struct s_rext
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_circle
{
	int		x;
	int		y;
	int		r;
	int		color;
}			t_circle;

typedef unsigned char	t_uchar;

/*
win_helper
*/
int		handle_keypress(int keysym, t_data *data);

/*
render
*/
int		*render_rainbow_color(int *color);
void	render_background(t_img *img, int color);
int		render_rect(t_data *data, t_img *img);
int		create_rect(t_img *img, t_rect rect);
int		render_circle(t_data *data, t_img *img);
void	create_circle(t_img *img, t_circle circle);

/*
make
*/

/*
put_pixel
*/

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

/*
color
*/

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		ctoi_create_trgb(t_uchar t, t_uchar r, t_uchar g, t_uchar b);
t_uchar	ctoi_get_t(int trgb);
t_uchar	ctoi_get_r(int trgb);
t_uchar	ctoi_get_g(int trgb);
t_uchar	ctoi_get_b(int trgb);

#endif