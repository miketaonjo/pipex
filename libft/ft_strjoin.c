/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:08:57 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/24 19:17:53 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	total;
	size_t	i;
	size_t	j;
	size_t	k;

	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * total);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
		str[j++] = s1[i++];
	k = 0;
	while (s2 && s2[k] != '\0')
	{
		str[j] = s2[k];
		j++;
		k++;
	}
	str[j] = '\0';
	return (str);
}
