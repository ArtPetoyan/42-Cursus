/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:35:49 by apetoyan          #+#    #+#             */
/*   Updated: 2025/06/03 19:17:15 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>

typedef struct g_com_v
{
	char	**paths;
	char	*p;
	char	*fp;
	char	**cmd1;
	int		i;
}	t_g_com_v;

typedef struct my_vars
{
	int		fd[2];
	int		input;
	int		output;
	char	*path1;
	char	**arg1;
	pid_t	pi;
	pid_t	pi2;
}	t_my_vars;

void	f(char **str, char *arr, char *arr1);
void	exit_failure(char *msg, int exit_number);
char	*get_command_path(char *cmd, char **envp);

#endif
