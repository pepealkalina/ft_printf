/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:48:42 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/07 19:39:57 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignedlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_printu(unsigned int nb)
{
	if (nb > 9)
		ft_printu(nb / 10);
	ft_printchar('0' + (nb % 10));
	return (ft_unsignedlen(nb));
}

int	ft_printp(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_printstr("0x");
	len += ft_print_ptr(ptr);
	return (len);
}

int	ft_printh(long long nbr, int flag)
{
	int	len;

	len = 0;
	if (flag == 0)
		len += ft_print_ptr(nbr);
	if (flag == 1)
		len += ft_print_hex(nbr);
	return (len);
}

int	ft_print_hex(long long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += ft_printchar('0');
	else if (nbr > 0)
	{
		if (nbr >= 16)
			len += ft_print_hex(nbr / 16);
		if ((nbr % 16) >= 10)
			len += ft_printchar('7' + (nbr % 16));
		else
			len += ft_printchar('0' + nbr % 16);
	}
	return (len);
}
