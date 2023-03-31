/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:40:58 by mcloarec          #+#    #+#             */
/*   Updated: 2022/04/21 14:32:53 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	t;

	t = 0;
	if (!dest && !src)
		return (0);
	while (t < n)
	{
		((unsigned char *)dest)[t] = ((unsigned const char *)src)[t];
		t++;
	}
	return (dest);
}
