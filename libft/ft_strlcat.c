/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:38 by mcloarec          #+#    #+#             */
/*   Updated: 2022/03/31 17:48:06 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (j > size)
		return (size + ft_strlen(src));
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	k = 0;
	while (size > (j + 1) && src[k] != '\0')
	{
		dst[i] = src[k];
		i++;
		k++;
		size--;
	}
	dst[i] = '\0';
	return (j + ft_strlen(src));
}
