/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:10:43 by mcloarec          #+#    #+#             */
/*   Updated: 2022/05/12 17:53:08 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenhexaint(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_check_x(char *str, unsigned int n, char c, int i)
{
	while (n > 0)
	{
		if ((n % 16) < 10)
		{
			str[--i] = 48 + (n % 16);
			n = n / 16;
		}
		else
		{
			if (c == 'x')
			{
				str[--i] = 87 + (n % 16);
				n = n / 16;
			}
			else if (c == 'X')
			{
				str[--i] = 55 + (n % 16);
				n = n / 16;
			}
		}
	}
}

static char	*ft_hexaitoa(unsigned int n, char c)
{
	char	*str;
	int		i;

	i = ft_lenhexaint(n);
	str = ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	ft_check_x(str, n, c, i);
	return (str);
}

int	ft_printhexa(unsigned int n, char c)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_hexaitoa(n, c);
	len = ft_printstr(num);
	free(num);
	return (len);
}
