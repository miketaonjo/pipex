/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:54:46 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/01 15:07:16 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	exit_error(char *message)
{
	perror(message);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

char	*join_loop(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		str = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		str[j++] = s2[i++];
	if (s1)
		free((char *)s1);
	str[j] = '\0';
	return (str);
}

void	close_fd(t_shell *pipes)
{
	close(pipes->file1);
	close(pipes->file2);
}

void	close_pipe_fd(t_shell *pipes)
{
	close(pipes->pipe_fd[0]);
	close(pipes->pipe_fd[1]);
}
