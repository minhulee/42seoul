/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:36 by jewlee            #+#    #+#             */
/*   Updated: 2024/08/02 11:30:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	init_info(t_info *info, char **envp)
{
	ft_memset(info, 0, sizeof(t_info));
	if (init_envp(info, envp) == FAIL)
		exit(FAIL);
	tcgetattr(ttyslot(), &info->og_term);
	info->pwd = ft_strdup(getenv("PWD"));
	return (SUCCESS);
}
