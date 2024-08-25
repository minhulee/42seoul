/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:50 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 18:10:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/fcntl.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

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
	WALL
}	t_tile_type;

typedef enum wall_type
{
	NO = 0,
	SO,
	WE,
	EA
}	t_wall_type;

typedef	struct s_map_data
{
	t_tile_type	**map;
	int			width;
	int			height;
	int			floor[3];
	int			ceil[3];
	void		*walls[4];
}	t_map_data;

typedef struct s_cub3d
{
	void		*mlx;
	void		*window;
	t_map_data	map_data;
}	t_cub3d;

/* 0_exit */
void	ft_err(char *err);

/* 1_parsing */
void	parsing(t_cub3d *info, char *file);
char	*remove_spaces(char *src);
void	*load_xpm(t_cub3d *info, char *path, int size);
t_bool	is_valid_file_name(char *file);

#endif