/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:54:06 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/07 15:02:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../srcs/libft/libft_include/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>

/*---Window_Size---*/
# define WINDOW_WIDTH	2560
# define WINDOW_HEIGHT	1440
/*-----------------*/

/*---Map---*/
# define SIZE			32
# define WALL			"./texture/map/wall.xpm"
# define FLOOR			"./texture/map/floor.xpm"
# define ESCAPE			"./texture/map/esc.xpm"
# define ITEM			"./texture/map/coin.xpm"
# define PLAYER			"./texture/player/p_idle_front1.xpm"
/*---------*/

/*---Keycode---*/
// # define KEY_ESC		53
// # define KEY_W			13
// # define KEY_A			0
// # define KEY_S			1
// # define KEY_D			2
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
/*-------------*/

/*---Structure_Declaration---*/
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

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	size_t	map_w;
	size_t	map_h;
	size_t	x;
	size_t	y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	player_cnt;
	size_t	exit_cnt;
	size_t	coin_cnt;
	size_t	coin_flag;
	size_t	coin_path_flag;
	size_t	exit_path_flag;
	size_t	walk_cnt;
	t_img	*texture;
}				t_game;
/*---------------------------*/

/*---Windows_Related---*/
void	ft_mlx_init(t_game *game);
void	ft_create_window(t_game *data, t_img *texture);
int		ft_closing_process(t_game *data);
/*---------------------*/

/*---Texture_Related---*/
void	ft_init_texture(t_game *game, t_img *texture);
/*--------------------*/

/*---Map_Related---*/
void	ft_init_map(int argc, char **argv, t_game *game);
void	ft_input_map(int fd, t_game *game);
void	ft_create_map(t_game *game, t_img *texture);
void	ft_put_img(t_game *game, void	*img, int x, int y);
/*---------------*/

/*---Keypress_Event---*/
int		ft_key_hook(int keycode, t_game *game);
void	ft_move_wasd(t_game *game, t_img *texture, int x, int y);
void	ft_move_player(t_game *game, t_img *texture, int x, int y);
/*--------------------*/

/*---Check---*/
void	ft_check_arg(int argc, char **argv);
void	ft_check_map(t_game *game);
void	ft_mapcheck_empty(t_game *game);
void	ft_mapcheck_blank_line(char *line);
void	ft_mapcheck_matrix(t_game *game);
void	ft_mapcheck_character(t_game *game);
void	ft_mapcheck_large_map(t_game *game);
void	ft_mapcheck_invalid_ch(t_game *game);
void	ft_mapcheck_required_ch(t_game *game);
void	ft_set_start_end(t_game *game, size_t x, size_t y);
void	ft_mapcheck_duplicates_ch(t_game *game);
void	ft_mapcheck_wall_less(t_game *game);
void	ft_mapcheck_path(t_game *game);
void	ft_coin_path_search(t_game *game, size_t count, size_t x, size_t y);
void	ft_exit_path_search(t_game *game, size_t x, size_t y);
void	ft_return_map(t_game *game);
/*-----------*/

/*---Error---*/
void	ft_error_msg(char *error_msg);
/*-----------*/

/*---Helper---*/
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_solong(const char *s1, const char *s2);
/*------------*/

#endif