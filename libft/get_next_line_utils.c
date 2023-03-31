/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:20:55 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/03 13:20:58 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free((char *)s1);
	return (dest);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	else if (ft_strlen(s + start) < len)
		str = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i] && i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
