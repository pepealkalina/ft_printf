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

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_numlen(int i)
{
	int	j;

	j = 0;
	if (i == -2147483648)
		return (11);
	if (i == 0)
		return (1);
	else if (i < 0)
	{
		j++;
		i = i * -1;
	}
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_printchar('8');
	}
	else if (nb < 0)
	{
		ft_printchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_printchar('0' + (nb % 10));
	}
	return (ft_numlen(nb));
}
