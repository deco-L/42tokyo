/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:54:06 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/25 12:46:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../srcs/libft/libft.h"
# include "../srcs/libft/printf/ft_printf.h"
# include "../srcs/libft/get_next_line/get_next_line_bonus.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

/*---Window_Size---*/
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600
/*-----------------*/

/*---Map---*/
# define SIZE 32
# define WALL "./texture/map/wall.xpm"
# define FLOOR "./texture/map/floor.xpm"
# define ESCAPE "./texture/map/esc.xpm"
# define ITEM "./texture/map/item.xpm"
# define PLAYER "./texture/player/p_idle_f.xpm"
/*---------*/

/*---Keycode---*/
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
/*-------------*/

/*---Structure_Declaration---*/
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	size_t	map_w;
	size_t	map_h;
	int		x;
	int		y;
	int		walk_cnt;
}				t_game;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*item;
	void	*esc;
	void	*player;
	int		wall_w;
	int		wall_h;
	int		floor_w;
	int		floor_h;
	int		item_w;
	int		item_h;
	int		esc_w;
	int		esc_h;
	int		player_w;
	int		player_h;
}				t_img;
/*---------------------------*/

/*---Windows_Related---*/
void	ft_create_window(t_game *data, t_img *texture);
int		ft_closing_process(t_game *data);
/*---------------------*/

/*---Texture_Related---*/
void	ft_init_texture(t_game *game, t_img *texture);
/*--------------------*/

/*---Map_Related---*/
void	ft_check_map(t_game *game);
void	ft_init_map(int argc, char **argv, t_game *game, t_img *texture);
void	ft_input_map(int fd, t_game *game);
void	ft_create_map(t_game *game, t_img *texture);
void	ft_set_player(t_game *game);
/*---------------*/

/*---Keypress_Event---*/
int		ft_key_hook(int keycode, t_game *game);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);
/*--------------------*/

/*---Check---*/
void	ft_check_arg(int argc, char **argv);
/*-----------*/

/*---Error---*/
void	ft_error_msg(char *error_msg);
/*-----------*/

/*---Helper---*/
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_solong(const char *s1, const char *s2);
/*------------*/

#endif