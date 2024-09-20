/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:50 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 16:57:52 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/fcntl.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# include <math.h>
# include <stdio.h>

# define NONE -1
# define MOVE_SPD 0.02
# define ROT_SPD 0.03
# define WINDOW_W 1980
# define WINDOW_H 1080
# define TEXTURE_W 64
# define TEXTURE_H 64

/* key event */
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define ESC					53
# define W						13
# define A						0
# define S						1
# define D						2
# define LEFT					123
# define RIGHT					124

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
	START,
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
	EA
}	t_wall_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map_data
{
	t_tile_type	**map;
	int			start;
	int			width;
	int			height;
	int			floor;
	int			ceil;
	int			*walls[4];
}	t_map_data;

typedef struct s_input
{
	int		w_s;
	int		a_d;
	int		l_r;
	t_bool	move[4];
	t_bool	rotate[2];
}	t_input;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
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
	t_map_data	map_data;
	t_input		input;
	t_player	player;
	t_camera	camera;
	t_ray		ray;
}	t_cub3d;

/* test */
void	test_map_array(t_map_data *map_data, t_tile_type **map);
void	check(void);

/* 0_exit */
void	ft_err(char *err);
void	ft_err_map(char *err, int row, int col);
int		exit_game(t_cub3d *info);

/* 1_parsing */
void	parsing(t_cub3d *info, char *file);
/* utils */
void	set_start(t_cub3d *info, int h, int w, t_tile_type type);
int		quick_open_file(char *file, int line);
char	*remove_space(char *src);
/* load */
void	load_xpm(t_cub3d *info, int **wall, char *path, int size);
/* valid */
void	is_valid_file_name(char *file);
void	is_valid_map(t_map_data *map_data, t_tile_type **map);
/* map */
void	convert_to_map(t_cub3d *info, t_map_data *map_data, char *file);

/* 2_event */
void	move(t_input *input, t_player *player, t_tile_type **map);
void	rotate(int key, t_player *player, t_camera *camera);
/* key */
t_bool	is_moved_tile(int x, int y, t_tile_type **map);
void	update_input(t_input *input);
void	update_player(t_cub3d *info, t_input *input);
int		press(int key, t_cub3d *info);
int		release(int key, t_cub3d *info);

/* 3_render */
int		render(t_cub3d *info);
/* calulate */
void	calc_ray_direction(t_ray *ray, t_player *player,
			t_camera *camera, int x);
void	calc_delta_dist(t_ray *ray);
void	calc_step_and_side_dist(t_ray *ray, t_player *player);
void	calc_dist(t_ray *ray, t_player *player);
void	calc_vertical_line(t_ray *ray, t_var *vars);
/* raycasting */
void	raycasting(t_cub3d *info, t_ray *ray,
			t_player *player, t_camera *camera);
/* util */
t_bool	is_locate_wall(t_player *player, t_map_data *map_data);
t_bool	is_out_of_map(t_player *player, t_map_data *map_data);

#endif