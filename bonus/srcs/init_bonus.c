/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:39:05 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/03 10:46:16 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	create_heredoc(t_shell *pipes, char **argv)
{
	char	*tmp;
	char	*str;

	str = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write (1, "heredoc > ", 10);
		tmp = get_next_line(0);
		if (!ft_strcmp(tmp, str))
		{
			free(tmp);
			pipes->hdoc = 1;
			break ;
		}
		if (tmp)
		{
			if (dup(pipes->file1) == ERROR)
				free_pipex(pipes, "Dup error");
			ft_putstr_fd(tmp, pipes->file1);
			free(tmp);
		}
	}
	free(str);
}

void	init_heredoc(t_shell *pipes, char **argv, char **envp)
{
	pipes->hdoc = 0;
	pipes->file1 = open(argv[1], (O_CREAT | O_WRONLY | O_TRUNC), 0666);
	if (pipes->file1 == ERROR)
		exit_error("File error");
	create_heredoc(pipes, argv);
	pipes->file1 = open(argv[1], O_RDONLY);
	if (pipes->file1 == ERROR)
		exit_error("File error");
	pipes->file2 = open(argv[5], (O_RDWR | O_APPEND | O_CREAT), 0666);
	if (pipes->file2 == ERROR)
		exit_error("File error");
	pipes->cmd1 = ft_split(argv[3], ' ');
	pipes->cmd2 = ft_split(argv[4], ' ');
	find_path(pipes, envp);
	pipes->nb_cmd = 2;
	pipes->path_cmd1 = NULL;
	pipes->path_cmd2 = NULL;
	pipes->path_cmd1 = get_path(pipes, pipes->cmd1[0]);
	pipes->path_cmd2 = get_path(pipes, pipes->cmd2[0]);
}

void	create_cmd(t_shell *pipes, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	pipes->nb_cmd = argc - 3;
	pipes->cmd = NULL;
	pipes->cmd = ft_calloc(sizeof(t_cmd), pipes->nb_cmd);
	if (!pipes->cmd)
	{
		free_tab(pipes->path);
		close_fd(pipes);
		exit_error("Malloc error");
	}
	while (j < argc - 1)
	{
		pipes->cmd[i].name_cmd = ft_split(argv[j], ' ');
		pipes->cmd[i].path_cmd = NULL;
		pipes->cmd[i].path_cmd = get_path(pipes, pipes->cmd[i].name_cmd[0]);
		i++;
		j++;
	}
}

void	init_mult_pipes(t_shell *pipes, int argc, char **argv, char **envp)
{
	pipes->file1 = open(argv[1], O_RDONLY);
	if (pipes->file1 == ERROR)
		exit_error("File error");
	pipes->file2 = open(argv[argc - 1], (O_RDWR | O_TRUNC | O_CREAT), 0666);
	if (pipes->file2 == ERROR)
		exit_error("File error");
	find_path(pipes, envp);
	create_cmd(pipes, argc, argv);
}
