/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:50 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:17 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <sys/fcntl.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# include <math.h>
# include <stdio.h>

# define NONE -1
# define WINDOW_W 1600
# define WINDOW_H 900
# define MOVE_SPD 0.05
# define ROT_SPD 0.00035
# define RATE 1.7
# define TEXTURE_W 64
# define TEXTURE_H 64
# define MINIMAP_H (WINDOW_H / 3 / 9 * 9)
# define MINIMAP_L (MINIMAP_H / 9)
# define MINIMAP_W (MINIMAP_H + (MINIMAP_L * 2))

/* key event */
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define ESC					53
# define W						13
# define A						0
# define S						1
# define D						2
# define F						3
# define LEFT					123
# define RIGHT					124
# define SHIFT					257

typedef enum e_bool
{
	FAIL = -1,
	FALSE,
	TRUE
}	t_bool;

typedef enum e_tile_type
{
	EMPTY = -1,
	GROUND,
	WALL,
	DOOR,
	ST_N,
	ST_S,
	ST_W,
	ST_E
}	t_tile_type;

typedef enum wall_type
{
	NO = 0,
	SO,
	WE,
	EA,
	DR
}	t_wall_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tile
{
	t_tile_type	type;
	t_bool		status;
}	t_tile;

typedef struct s_map_data
{
	t_tile		**map;
	int			start;
	int			width;
	int			height;
	int			floor;
	int			ceil;
	int			*walls[5];
}	t_map_data;

typedef struct s_input
{
	int		w_s;
	int		a_d;
	int		l_r;
	t_bool	move[4];
	t_bool	rotate[2];
	t_bool	run;
	t_tile	*open_dst;
}	t_input;

typedef struct s_action
{
	t_img	*texture;
	int		time;
	int		frame;
	t_bool	flag;
}	t_action;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		mov_spd;
	int			time;
	int			frame;
	t_bool		flag;
	t_action	left_pist;
	t_img		right_pist;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	x_spd;
	double	tov;
	int		prev_x;
	int		prev_y;
	int		key;
	int		time;
	int		frame;
	t_bool	flag;
}	t_camera;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist;
	t_bool	is_hit;
	t_bool	is_side;
	t_bool	is_door;
}	t_ray;

typedef struct s_var
{
	int			line_h;
	int			draw_st;
	int			draw_en;
	int			color;
	int			tex_num;
	t_wall_type	type;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}	t_var;

typedef struct s_cub3d
{
	void		*mlx;
	void		*window;
	t_img		screen;
	t_img		button;
	t_map_data	map_data;
	t_input		input;
	t_player	player;
	t_camera	camera;
	t_ray		ray;
}	t_cub3d;

/* 0_exit */
void	ft_err(char *err);
void	ft_err_map(char *err, int row, int col);

/* 1_parsing */
void	parsing(t_cub3d *info, char *file);
/* utils */
void	set_start(t_cub3d *info, int h, int w, t_tile_type type);
int		quick_open_file(char *file, int line);
char	*remove_space(char *src);
void	test_map_array(t_map_data *map_data, t_tile **map);
/* load */
void	load_xpm(t_cub3d *info, int **wall, char *path, int size);
/* valid */
void	is_valid_file_name(char *file);
void	is_valid_map(t_map_data *map_data, t_tile **map);
/* map */
void	convert_to_map(t_cub3d *info, t_map_data *map_data, char *file);

/* 2_event */
/* key */
t_bool	is_moved_tile(t_input *input, int x, int y, t_map_data *map_data);
void	update_input(t_cub3d *info, t_input *input);
void	update_player(t_cub3d *info, t_input *input);
int		press(int key, t_cub3d *info);
int		release(int key, t_cub3d *info);
/* mouse */
int 	click(int key, int x, int y, t_cub3d *info);
/* move */
void	move(t_cub3d *info, t_input *input,
			t_player *player, t_map_data *map_data);
/* camera */
void	rotate(t_cub3d *info, int key, t_player *player, t_camera *camera);
void	update_camera(t_cub3d *info);

/* 3_render */
int		render(t_cub3d *info);
/* calulate */
void	calc_ray_direction(t_ray *ray, t_player *player,
			t_camera *camera, int x);
void	calc_delta_dist(t_ray *ray);
void	calc_step_and_side_dist(t_ray *ray, t_player *player);
void	calc_dist(t_ray *ray, t_player *player);
void	calc_vertical_line(t_ray *ray, t_camera *camera, t_var *vars);
/* raycasting */
void	raycasting(t_cub3d *info, t_ray *ray,
			t_player *player, t_camera *camera);
/* minimap */
void	make_minimap(t_cub3d *info);
/* util */
t_bool	is_locate_wall(t_player *player, t_map_data *map_data);

#endif