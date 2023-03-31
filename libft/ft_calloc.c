/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:36:02 by mcloarec          #+#    #+#             */
/*   Updated: 2022/04/11 16:43:10 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;

	if (size > 2147483647 || nmemb > 2147483647)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p || (nmemb * size > 2147483647))
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
