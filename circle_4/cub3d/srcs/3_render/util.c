/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:14 by jewlee            #+#    #+#             */
/*   Updated: 2024/09/04 11:03:14 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	is_locate_wall(t_player *player, t_map_data *map_data)
{
	if (map_data->map[player->map_y][player->map_x] == WALL)
		return (TRUE);
	return (FALSE);
}

t_bool	is_out_of_map(t_player *player, t_map_data *map_data)
{
	if (player->map_x < 0 || player->map_x >= map_data->width
		|| player->map_y < 0 || player->map_y >= map_data->height)
		return (TRUE);
	if (map_data->map[player->map_y][player->map_x] == EMPTY)
		return (TRUE);
	return (FALSE);
}
