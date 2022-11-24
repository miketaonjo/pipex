/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:52:15 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/01 18:37:31 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_pipex(t_shell *pipes, char *message)
{
	free_path_cmd(pipes, message);
	if (pipes->path_cmd2 != NULL)
		free(pipes->path_cmd2);
	if (pipes->hdoc == 1)
		unlink("here_doc");
}

void	free_path_cmd(t_shell *pipes, char *message)
{
	free_tab(pipes->path);
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	if (pipes->path_cmd1 != NULL)
		free(pipes->path_cmd1);
	close_fd(pipes);
	if (pipes->hdoc == 1)
		unlink("here_doc");
	if (message[0] != '\0')
		exit_error(message);
}

void	free_cmd(t_shell *pipes, char *message)
{
	free(pipes->path_cmd1);
	free(pipes->path_cmd2);
	free_cmd_tab(pipes, message);
}

void	free_cmd_tab(t_shell *pipes, char *message)
{
	free_tab(pipes->cmd1);
	free_tab(pipes->cmd2);
	close_fd(pipes);
	if (pipes->hdoc == 1)
		unlink("here_doc");
	exit_error(message);
}
