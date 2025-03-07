/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:00:07 by jewlee            #+#    #+#             */
/*   Updated: 2024/08/02 11:32:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_str(char **s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != NULL)
		cnt++;
	return (cnt);
}

static char	**init_dup_envp(char **envp)
{
	int		size;
	int		i;
	char	**dup_envp;

	size = count_str(envp);
	dup_envp = ft_calloc(size + 1, sizeof(char *));
	if (!dup_envp)
		exit(FAIL);
	i = -1;
	while (++i < size)
	{
		dup_envp[i] = ft_strdup(envp[i]);
		if (dup_envp[i] == NULL)
		{
			while (--i >= 0)
				free(dup_envp[i]);
			free(dup_envp);
			return (NULL);
		}
	}
	dup_envp[i] = NULL;
	return (dup_envp);
}

t_status	init_envp(t_info *info, char **envp)
{
	int		i;
	char	*content;
	t_list	*new;

	info->og_envp = envp;
	info->dup_envp = init_dup_envp(envp);
	i = -1;
	info->env_lst = NULL;
	while (info->dup_envp[++i] != NULL)
	{
		content = ft_strdup(info->dup_envp[i]);
		if (content == NULL)
			return (FAIL);
		new = ft_lstnew(content);
		if (new == NULL)
		{
			ft_lstclear(&(info->env_lst), free);
			return (FAIL);
		}
		ft_lstadd_back(&(info->env_lst), new);
	}
	return (SUCCESS);
}
