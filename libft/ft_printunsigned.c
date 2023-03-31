/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:52:10 by mcloarec          #+#    #+#             */
/*   Updated: 2022/05/12 17:54:53 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(unsigned	int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_unsitoa(unsigned int n)
{
	char	*unsint;
	int		len;

	len = ft_lenint(n);
	unsint = (char *)malloc(sizeof(char) * (len + 1));
	if (!unsint)
		return (NULL);
	unsint[len] = '\0';
	while (n != 0)
	{
		unsint[--len] = 48 + (n % 10);
		n = n / 10;
	}
	return (unsint);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*unsint;

	len = 0;
	if (n == 0)
		len = len + ft_printchar('0');
	else
	{
		unsint = ft_unsitoa(n);
		len = len + ft_printstr(unsint);
		free(unsint);
	}
	return (len);
}
