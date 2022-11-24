/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:09:20 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/21 15:20:22 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child2_exec(t_shell pipes, char **envp)
{
	if (dup2(pipes.pipe_fd[0], STDIN) == ERROR)
		free_close(&pipes, "Dup error");
	if (dup2(pipes.file2, STDOUT) == ERROR)
		free_close(&pipes, "Dup error");
	close(pipes.pipe_fd[1]);
	close(pipes.pipe_fd[0]);
	if (execve(pipes.path_cmd2, pipes.cmd2, envp) == ERROR)
		free_close(&pipes, "Execve error");
}

void	create_child2(t_shell pipes, char **envp)
{
	pipes.pid2 = fork();
	if (pipes.pid2 == ERROR)
		free_close(&pipes, "Fork error");
	else if (pipes.pid2 == 0)
		child2_exec(pipes, envp);
	else
	{
		if (waitpid(pipes.pid2, NULL, 0) == ERROR)
			free_close(&pipes, "Waitpid error");
		close(pipes.pipe_fd[0]);
		close(pipes.pipe_fd[1]);
		close(pipes.file1);
		close(pipes.file2);
	}
}

void	child1_exec(t_shell pipes, char **envp)
{
	if (dup2(pipes.file1, STDIN) == ERROR)
		free_close(&pipes, "Dup error");
	if (dup2(pipes.pipe_fd[1], STDOUT) == ERROR)
		free_close(&pipes, "Dup error");
	close(pipes.pipe_fd[0]);
	close(pipes.pipe_fd[1]);
	if (execve(pipes.path_cmd1, pipes.cmd1, envp) == ERROR)
		free_close(&pipes, "Execve error");
}

void	create_child1(t_shell pipes, char **envp)
{
	pipes.pid1 = fork();
	if (pipes.pid1 == ERROR)
		free_close(&pipes, "Fork error");
	else if (pipes.pid1 == 0)
		child1_exec(pipes, envp);
	else
	{
		if (waitpid(pipes.pid1, NULL, 0) == ERROR)
			free_close(&pipes, "Waitpid error");
		close(pipes.pipe_fd[1]);
	}
}
