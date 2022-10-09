/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:48:32 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/07 19:41:36 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//cspdiuxX%
int	ft_check_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_printchar('%');
	else if (c == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		len += ft_printp(va_arg(args, unsigned long long));
	else if (c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_printu(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_printh(va_arg(args, unsigned long long), 0);
	else if (c == 'X')
		len += ft_printh(va_arg(args, unsigned long long), 1);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		plen;
	va_list	argu;

	i = 0;
	plen = 0;
	va_start(argu, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			plen += ft_check_format(argu, str[i + 1]);
			i++;
		}
		else
			plen += ft_printchar(str[i]);
		i++;
	}
	va_end(argu);
	return (plen);
}

int main(void)
{
	int c = -6000023;
	printf("\n%i", ft_printf("%x", c));
	printf("\n%X", c);
	return 0;
}
