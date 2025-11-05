/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:37:08 by apetoyan          #+#    #+#             */
/*   Updated: 2025/03/22 15:58:55 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	main_helper_1(t_my_vars *vars, char **argv, char **envp)
{
	vars->input = open(argv[1], O_RDONLY);
	if (vars->input == -1)
		exit_failure("pipex: ", EXIT_FAILURE);
	vars->path1 = get_command_path(argv[2], envp);
	if (!vars->path1)
		exit_failure("command not found", EXIT_FAILURE);
	vars->arg1 = ft_split(argv[2], ' ');
	if (!vars->arg1)
	{
		free(vars->path1);
		exit_failure("malloc error", EXIT_FAILURE);
	}
	dup2(vars->input, STDIN_FILENO);
	dup2(vars->fd[1], STDOUT_FILENO);
	close(vars->fd[0]);
	close(vars->input);
	close(vars->fd[1]);
	if (execve(vars->path1, vars->arg1, envp) == -1)
	{
		f(vars->arg1, vars->path1, NULL);
		exit_failure("execve cmd1", EXIT_FAILURE);
	}
}

static void	main_helper_2(t_my_vars *vars, char **argv, char **envp)
{
	vars->output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->output == -1)
		exit_failure("cant open file", EXIT_FAILURE);
	vars->path1 = get_command_path(argv[3], envp);
	if (!vars->path1)
		exit_failure("command not found", 127);
	vars->arg1 = ft_split(argv[3], ' ');
	if (!vars->arg1)
	{
		free(vars->path1);
		exit_failure("malloc error", EXIT_FAILURE);
	}
	dup2(vars->fd[0], STDIN_FILENO);
	dup2(vars->output, STDOUT_FILENO);
	close(vars->fd[0]);
	close(vars->fd[1]);
	close(vars->output);
	if (execve(vars->path1, vars->arg1, envp) == -1)
	{
		f(vars->arg1, vars->path1, NULL);
		exit_failure("execve cmd2", EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_my_vars	vars;

	if (argc != 5)
		exit_failure("./pipex file1 cmd1 cmd2 file2", EXIT_FAILURE);
	if (pipe(vars.fd) == -1)
		exit_failure("pipex: ", EXIT_FAILURE);
	vars.pi = fork();
	if (vars.pi < 0)
		exit_failure("fork", EXIT_FAILURE);
	else if (vars.pi == 0)
		main_helper_1(&vars, argv, envp);
	vars.pi2 = fork();
	if (vars.pi2 < 0)
		exit_failure("fork", EXIT_FAILURE);
	else if (vars.pi2 == 0)
		main_helper_2(&vars, argv, envp);
	close(vars.fd[0]);
	close(vars.fd[1]);
	waitpid(vars.pi2, NULL, 0);
	waitpid(vars.pi, NULL, 0);
	return (0);
}
