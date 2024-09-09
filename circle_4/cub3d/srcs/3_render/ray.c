/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:03:11 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/09 10:36:41 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	execute_dda(t_ray *ray, t_player *player, t_map_data *map_data)
{
	ray->is_hit = FALSE;
	while (ray->is_hit == FALSE)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			player->map_x += ray->step_x;
			ray->is_side = TRUE;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			player->map_y += ray->step_y;
			ray->is_side = FALSE;
		}
		if (is_out_of_map(player, map_data) == TRUE
			|| is_locate_wall(player, map_data))
			ray->is_hit = TRUE;
	}
}

void	tex_ver_line(t_cub3d *info, t_var *vars, int start, int x)
{
	int	i;
	int	color;
	int	**walls;

	vars->step = 1.0 * TEXTURE_H / vars->line_h;
	vars->tex_pos = (start - WINDOW_H / 2 + vars->line_h / 2) * vars->step;
	walls = info->map_data.walls;
	i = 0;
	while (i < WINDOW_H)
	{
		if (i < start)
			color = info->map_data.ceil;
		else if (i > vars->draw_en)
			color = info->map_data.floor;
		else
		{
			vars->tex_y = (int)vars->tex_pos & 63;
			vars->tex_pos += vars->step;
			color = walls[vars->tex_num][TEXTURE_H * vars->tex_y + vars->tex_x];
		}
		info->buff[i][x] = color;
		i++;
	}
}

void	select_wall(t_var *vars, t_ray *ray)
{
	if (ray->is_side == FALSE && ray->dir_y < 0)
		vars->tex_num = NO;
	if (ray->is_side == FALSE && ray->dir_y > 0)
		vars->tex_num = SO;
	if (ray->is_side == TRUE && ray->dir_x < 0)
		vars->tex_num = EA;
	if (ray->is_side == TRUE && ray->dir_x > 0)
		vars->tex_num = WE;
}

void	raycasting(t_cub3d *info, t_ray *ray,
	t_player *player, t_camera *camera)
{
	t_var	vars;
	int		x;

	x = -1;
	while (++x < WINDOW_W)
	{
		calc_ray_direction(ray, player, camera, x);
		calc_delta_dist(ray);
		calc_step_and_side_dist(ray, player);
		execute_dda(ray, player, &info->map_data);
		calc_dist(ray, player);
		calc_vertical_line(ray, &vars);
		select_wall(&vars, ray);
		if (ray->is_side == FALSE)
			vars.wall_x = player->pos_y + ray->dist * ray->dir_y;
		else
			vars.wall_x = player->pos_x + ray->dist * ray->dir_x;
		vars.wall_x -= floor(vars.wall_x);
		vars.tex_x = (int)(vars.wall_x * (double)TEXTURE_W);
		if (ray->is_side == FALSE && ray->dir_x > 0)
			vars.tex_x = TEXTURE_W - vars.tex_x - 1;
		if (ray->is_side == TRUE && ray->dir_y < 0)
			vars.tex_x = TEXTURE_W - vars.tex_x - 1;
		tex_ver_line(info, &vars, vars.draw_st, x);
	}
}
