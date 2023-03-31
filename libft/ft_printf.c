/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:44:45 by mcloarec          #+#    #+#             */
/*   Updated: 2022/05/12 17:52:47 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(va_list args, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (str == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (str == 'p')
		len = ft_printptr(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		len = ft_printnbr(va_arg(args, int));
	else if (str == 'u')
		len = ft_printunsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		len = ft_printhexa(va_arg(args, unsigned int), str);
	else if (str == '%')
		len = ft_printpercent();
	else
		return (0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len = len + ft_type(args, str[i + 1]);
			i++;
		}
		else
			len = len + ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
