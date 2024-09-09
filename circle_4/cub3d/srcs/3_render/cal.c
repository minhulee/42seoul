/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:35:33 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/09 11:31:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// 여기서 sidedist x 는 side y 이다!
// delta 도 동일하다.
void	calc_ray_direction(t_ray *ray, t_player *player,
	t_camera *camera, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WINDOW_W - 1;
	ray->dir_x = player->dir_x + camera->plane_x * camera_x;
	ray->dir_y = player->dir_y + camera->plane_y * camera_x;
}

void	calc_delta_dist(t_ray *ray)
{
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	calc_step_and_side_dist(t_ray *ray, t_player *player)
{
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - player->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (player->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - player->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	calc_dist(t_ray *ray, t_player *player)
{
	if (ray->is_side == FALSE)
		ray->dist = (player->map_y - player->pos_y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	else
		ray->dist = (player->map_x - player->pos_x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
}

void	calc_vertical_line(t_ray *ray, t_var *vars)
{
	printf("%f\n", ray->dist);
	vars->line_h = (int)(WINDOW_H / ray->dist);
	if (vars->line_h < 0)
		vars->line_h = WINDOW_H;
	vars->draw_st = -vars->line_h / 2 + WINDOW_H / 2;
	if (vars->draw_st < 0)
		vars->draw_st = 0;
	vars->draw_en = vars->line_h / 2 + WINDOW_H / 2;
	if (vars->draw_en >= WINDOW_H)
		vars->draw_en = WINDOW_H - 1;
}
