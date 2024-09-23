/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:20:46 by jewlee            #+#    #+#             */
/*   Updated: 2024/08/02 11:22:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

void	builtins_env(t_info *info)
{
	int	i;

	info->exit_status = SUCCESS;
	i = -1;
	while (info->dup_envp[++i] != NULL)
	{
		if (ft_strchr(info->dup_envp[i], '=') != NULL)
			ft_fprintf(STDOUT_FILENO, "%s\n", info->dup_envp[i]);
	}
}
