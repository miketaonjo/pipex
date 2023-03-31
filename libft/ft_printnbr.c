/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:26:13 by mcloarec          #+#    #+#             */
/*   Updated: 2022/05/12 17:56:07 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(int n)
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

static char	*itoa(int n)
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

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	num = itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
