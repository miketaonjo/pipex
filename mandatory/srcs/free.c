/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:32:43 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/21 15:36:31 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_pipex(t_shell *pipes)
{
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	free_tab(pipes->path);
	if (pipes->path_cmd1 != NULL)
		free(pipes->path_cmd1);
	if (pipes->path_cmd2 != NULL)
		free(pipes->path_cmd2);
	close(pipes->file1);
	close(pipes->file2);
	close(pipes->pipe_fd[0]);
	close(pipes->pipe_fd[0]);
}

void	free_close(t_shell *pipes, char *message)
{
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	free_tab(pipes->path);
	if (pipes->path_cmd1 != NULL)
		free(pipes->path_cmd1);
	if (pipes->path_cmd2 != NULL)
		free(pipes->path_cmd2);
	close(pipes->file1);
	close(pipes->file2);
	exit_error(message);
}

void	free_path(t_shell *pipes, char *message)
{
	free_tab(pipes->path);
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	if (pipes->path_cmd1 != NULL)
		free(pipes->path_cmd1);
	close(pipes->file1);
	close(pipes->file2);
	exit_error(message);
}

void	free_path_cmd(t_shell *pipes, char *message)
{
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	free(pipes->path_cmd1);
	free(pipes->path_cmd2);
	close(pipes->file1);
	close(pipes->file2);
	exit_error(message);
}

void	free_cmd(t_shell *pipes, char *message)
{
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	close(pipes->file1);
	close(pipes->file2);
	exit_error(message);
}
