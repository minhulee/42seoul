/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:56:40 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 11:19:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	parsing(t_cub3d *info, char *file)
{
	int	fd;

	(void)info;
	if (!is_valid_file_name(file))
		ft_err("parsing :: invalid file name.");
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_err("parsing :: failed open file.");
	return (TRUE);
}
