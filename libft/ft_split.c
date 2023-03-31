/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:55:22 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/20 18:02:32 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_slen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **s, int i)
{
	while (i > 0)
	{
		free (s[i]);
		i--;
	}
	free (s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_substr(s, i, ft_slen(s, c, i));
		tab[j][ft_slen(s, c, i)] = '\0';
		if (!tab)
		{
			ft_free(tab, j);
			return (NULL);
		}
		i = i + ft_slen(s, c, i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
