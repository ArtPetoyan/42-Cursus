/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:22:44 by apetoyan          #+#    #+#             */
/*   Updated: 2025/03/13 21:30:13 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_command_path_helper(char **envp, char ***paths)
{
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (!*envp)
		return (0);
	*paths = ft_split(*envp + 5, ':');
	if (!*paths)
		return (0);
	return (1);
}

char	*get_command_path(char *cmd, char **envp)
{
	t_g_com_v	v;

	if (!get_command_path_helper(envp, &v.paths))
		return (NULL);
	v.i = 0;
	while (v.paths[v.i])
	{
		v.cmd1 = ft_split(cmd, ' ');
		if (!v.cmd1)
			return (NULL);
		v.p = ft_strjoin(v.paths[v.i], "/");
		if (!v.p)
			return (NULL);
		if (!(v.cmd1[0][0] == '/'))
			v.fp = ft_strjoin(v.p, v.cmd1[0]);
		else
			v.fp = ft_strjoin(v.p, ft_strrchr(v.cmd1[0], '/') + 1);
		if (!v.fp)
			return (free(v.p), NULL);
		if (!access(v.fp, X_OK))
			return (f(v.paths, NULL, v.p), f(v.cmd1, NULL, NULL), v.fp);
		f(v.cmd1, v.fp, v.p);
		(v.i)++;
	}
	return (f(v.paths, NULL, NULL), NULL);
}

void	exit_failure(char *msg, int exit_number)
{
	if (errno == 0)
		errno = EIO;
	perror(msg);
	exit(exit_number);
}

void	f(char **str, char *arr, char *arr1)
{
	int	i;

	i = 0;
	if (arr)
		free(arr);
	if (arr1)
		free(arr1);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
