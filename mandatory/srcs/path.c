/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:47:20 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/21 15:00:44 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_path_cmd(char *path_cmd)
{
	if (access(path_cmd, F_OK | X_OK))
		return (0);
	else
		return (-1);
}

char	*get_path(t_shell *pipes, char *path_cmd)
{
	char	*path;
	char	*path_test;
	int		i;

	if (access(path_cmd, X_OK) == 0)
		return (ft_strdup(path_cmd));
	i = -1;
	path = NULL;
	path_test = NULL;
	while (pipes->path[++i])
	{
		path = ft_strjoin(pipes->path[i], "/");
		path_test = ft_strjoin(path, path_cmd);
		free(path);
		if (check_path_cmd(path_test))
			return (path_test);
		free(path_test);
	}
	if (pipes->path[i] == NULL)
		free_path(pipes, "Cmd error");
	if (check_path_cmd(path_test) == ERROR)
		free_path_cmd(pipes, "Cmd error");
	return (path_test);
}

void	find_path(t_shell *pipes, char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i++])
	{
		if (!envp)
			free_cmd(pipes, "Env error");
		path = ft_strnstr(envp[i], "PATH", 5);
		if (path)
			break ;
	}
	if (!path)
		free_cmd(pipes, "Path error");
	pipes->path = ft_split(path + 5, ':');
}
