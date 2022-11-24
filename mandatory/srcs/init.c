/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:39:05 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/31 16:03:30 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_pipes(t_shell *pipes, char **argv, char **envp)
{
	pipes->file1 = open(argv[1], O_RDONLY);
	if (pipes->file1 == ERROR)
		exit_error("File error");
	pipes->file2 = open(argv[4], (O_RDWR | O_TRUNC | O_CREAT), 0666);
	if (pipes->file2 == ERROR)
		exit_error("File error");
	pipes->cmd1 = ft_split(argv[2], ' ');
	pipes->cmd2 = ft_split(argv[3], ' ');
	find_path(pipes, envp);
	pipes->path_cmd1 = NULL;
	pipes->path_cmd2 = NULL;
	pipes->path_cmd1 = get_path(pipes, pipes->cmd1[0]);
	pipes->path_cmd2 = get_path(pipes, pipes->cmd2[0]);
}
