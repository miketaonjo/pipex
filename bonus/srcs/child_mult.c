/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:33:20 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/01 15:35:38 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	child_last_cmd(t_shell *pipes, char **envp, int i)
{
	if (dup2(pipes->tab_pipe[pipes->nb_cmd - 2].fd[0], STDIN) == ERROR)
		free_close_mult(pipes, "Dup error");
	if (dup2(pipes->file2, STDOUT) == ERROR)
		free_close_mult(pipes, "Dup error");
	if (execve(pipes->cmd[i].path_cmd,
			pipes->cmd[i].name_cmd, envp) == ERROR)
		free_close_mult(pipes, "Execve error");
}

void	child_n_cmd(t_shell *pipes, char **envp, int i)
{
	if (dup2(pipes->tab_pipe[i - 1].fd[0], STDIN) == ERROR)
		free_close_mult(pipes, "Dup error");
	if (dup2(pipes->tab_pipe[i].fd[1], STDOUT) == ERROR)
		free_close_mult(pipes, "Dup error");
	if (execve(pipes->cmd[i].path_cmd, pipes->cmd[i].name_cmd, envp) == ERROR)
		free_close_mult(pipes, "Execve error");
}

void	child_cmd1(t_shell *pipes, char **envp)
{
	if (dup2(pipes->file1, STDIN) == ERROR)
		free_close_mult(pipes, "Dup error");
	if (dup2(pipes->tab_pipe[0].fd[1], STDOUT) == ERROR)
		free_close_mult(pipes, "Dup error");
	if (execve(pipes->cmd[0].path_cmd, pipes->cmd[0].name_cmd, envp) == ERROR)
		free_close_mult(pipes, "Execve error");
}

void	close_pipes(t_shell *pipes, int i)
{
	if (i > 0 && i != pipes->nb_cmd - 1)
		close(pipes->tab_pipe[i - 1].fd[0]);
	if (i < pipes->nb_cmd - 1)
		close(pipes->tab_pipe[i].fd[1]);
}

void	create_mult_cmd(t_shell *pipes, char **envp)
{
	int	i;

	i = 0;
	while (i < pipes->nb_cmd)
	{
		if (pipe(pipes->tab_pipe[i].fd) < 0 && i < pipes->nb_cmd - 1)
			free_mult_path_cmd(pipes, "Pipe error");
		pipes->cmd[i].pid = fork();
		if (pipes->cmd[i].pid == ERROR)
			free_mult_path_cmd(pipes, "Pid error");
		else if (i == 0 && pipes->cmd[0].pid == 0)
			child_cmd1(pipes, envp);
		else if (i > 0 && i < pipes->nb_cmd - 1 && pipes->cmd[i].pid == 0)
			child_n_cmd(pipes, envp, i);
		else if (i == pipes->nb_cmd - 1 && pipes->cmd[i].pid == 0)
			child_last_cmd(pipes, envp, i);
		else
		{
			if (waitpid(pipes->cmd[i].pid, NULL, 0) == ERROR)
				free_close_mult(pipes, "Waitpid error");
		}
		close_pipes(pipes, i);
		i++;
	}
	close(pipes->tab_pipe[i - 2].fd[0]);
}
