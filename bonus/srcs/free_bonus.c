/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:06:18 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/01 17:44:58 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_pipex_mult(t_shell *pipes, char *message)
{
	free_mult_path_cmd(pipes, message);
	free(pipes->tab_pipe);
	close_fd(pipes);
}

void	free_close_mult(t_shell *pipes, char *message)
{
	free_mult_path_cmd(pipes, message);
	close_fd(pipes);
}

void	choose_free_path(t_shell *pipes, char *message)
{
	if (pipes->nb_cmd > 2)
		free_close_mult(pipes, message);
	else
		free_path_cmd(pipes, message);
}

void	free_mult_path_cmd(t_shell *pipes, char *message)
{
	int	i;

	i = 0;
	free_tab(pipes->path);
	while (i < pipes->nb_cmd)
	{
		if (pipes->cmd[i].name_cmd != NULL)
			free_tab(pipes->cmd[i].name_cmd);
		if (pipes->cmd[i].path_cmd != NULL)
			free(pipes->cmd[i].path_cmd);
		i++;
	}
	if (pipes->cmd != NULL)
		free(pipes->cmd);
	if (message[0] != '\0')
		exit_error(message);
}

void	choose_free_pipex(t_shell *pipes, char *message)
{
	if (pipes->nb_cmd > 2)
		free_pipex_mult(pipes, message);
	else
		free_pipex(pipes, message);
}
