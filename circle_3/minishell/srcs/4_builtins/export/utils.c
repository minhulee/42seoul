/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:01:57 by jewlee            #+#    #+#             */
/*   Updated: 2024/08/02 11:22:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include <unistd.h>

void	free_dup_envp(t_info *info)
{
	int	i;

	i = -1;
	while (info->dup_envp[++i] != NULL)
		free(info->dup_envp[i]);
	free(info->dup_envp);
}

t_bool	is_valid_name(char *s)
{
	if (!(*s == '_' || ft_isalpha(*s)))
		return (FALSE);
	while (*(++s) != '\0')
	{
		if (!(*s == '_' || ft_isalnum(*s)))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	declare_is_existed(char *arg, char **envp)
{
	int		i;
	char	*name;

	i = -1;
	while (envp[++i] != NULL)
	{
		name = export_extract_name(envp[i]);
		if (!ft_strncmp(arg, name, ft_strlen(name) + 1))
		{
			free(name);
			return (TRUE);
		}
		free(name);
	}
	return (FALSE);
}

void	print_export(t_info *info)
{
	int		i;
	char	**envp;

	envp = info->dup_envp;
	i = -1;
	while (envp[++i] != NULL)
		ft_fprintf(STDOUT_FILENO, "declare -x %s\n", envp[i]);
}

void	export_fprintf_err(char *s, t_info *info)
{
	ft_fprintf(STDERR_FILENO,
		"minishell: export: %s: not a valid identifier\n", s);
	info->exit_status = FAIL;
}
