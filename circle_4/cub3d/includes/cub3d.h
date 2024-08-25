/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:50 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 11:18:07 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/fcntl.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# include "parsing.h"

typedef enum e_bool
{
	FAIL = -1,
	FALSE,
	TRUE
}	t_bool;

typedef struct s_cub3d
{
	void		*mlx;
	void		*window;
	t_map_data	map_data;
}	t_cub3d;

/* 0_exit */
void	ft_err(char *err);

/* 1_parsing */
t_bool	parsing(t_cub3d *info, char *file);
t_bool	is_valid_file_name(char *file);

#endif