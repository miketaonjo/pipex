/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:59:57 by mcloarec          #+#    #+#             */
/*   Updated: 2022/04/11 17:48:12 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkchar(char c, char const *set)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			cmpt++;
		i++;
	}
	return (cmpt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_checkchar(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	while (ft_checkchar(s1[j], set))
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}
