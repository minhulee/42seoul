/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 11:11:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum e_tile_type
{
	EMPTY = -1,
	GROUND,
	WALL
}	t_tile_type;

typedef	struct s_map_data
{
	t_tile_type	**map;
}	t_map_data;

#endif