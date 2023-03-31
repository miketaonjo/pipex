/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:17 by mcloarec          #+#    #+#             */
/*   Updated: 2022/04/22 09:18:45 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenint(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_lenint(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[--i] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}
