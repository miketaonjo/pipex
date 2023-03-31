/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:20:01 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/03 13:20:28 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_fd(char *buf, int file_d)
{
	char	*tmp;
	int		rd;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
	{
		free (buf);
		return (NULL);
	}
	rd = 1;
	while (find_bsn(buf) == -1 && rd != 0)
	{
		rd = read(file_d, tmp, BUFFER_SIZE);
		if (rd == -1)
		{	
			free (buf);
			free (tmp);
			return (NULL);
		}
		tmp[rd] = '\0';
		buf = ft_strjoin_gnl(buf, tmp);
	}
	free (tmp);
	return (buf);
}

int	find_bsn(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*recup_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return (ft_substr_gnl(buf, 0, i + 1));
}

char	*new_buffer(char *old_buf)
{
	int		i;
	char	*new_buf;

	i = 0;
	if (ft_strlen(old_buf) == 0)
	{
		free(old_buf);
		return (NULL);
	}
	while (old_buf[i] != '\0' && old_buf[i] != '\n')
		i++;
	if (old_buf[i] == '\n')
		new_buf = ft_substr_gnl(old_buf, i + 1, ft_strlen(old_buf + i + 1));
	else
	{
		new_buf = ft_substr_gnl(old_buf, i, 1);
	}
	if (*new_buf == '\0')
	{
		free(new_buf);
		new_buf = NULL;
	}
	free(old_buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd == -1 && BUFFER_SIZE == 0)
		return (NULL);
	if (buffer[fd] == NULL)
	{
		buffer[fd] = malloc(sizeof(char));
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = read_fd(buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (NULL);
	line = recup_line(buffer[fd]);
	buffer[fd] = new_buffer(buffer[fd]);
	if (line[0] == '\0')
	{
		free (line);
		free (buffer[fd]);
		return (NULL);
	}	
	return (line);
}
