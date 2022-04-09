/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csdu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 05:44:08 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/03/27 05:46:53 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	counter;

	if (!s)
		return (ft_putstr("(null)"));
	counter = 0;
	while (*s)
	{
		write(1, s, 1);
		counter++;
		s++;
	}	
	return (counter);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == (int) 0x80000000)
	{
		write(1, "-2", 2);
		n = 147483648;
		ret = 2;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ret = 1;
	}
	if (n < 10)
	{
		n += '0';
		write(1, &n, 1);
		return (ret + 1);
	}
	ret += ft_putnbr(n / 10);
	n = '0' + n % 10;
	write(1, &n, 1);
	return (ret + 1);
}

int	ft_putunbr(unsigned int n)
{
	int	ret;

	if (n < 10)
	{
		n += '0';
		write(1, &n, 1);
		return (1);
	}
	ret = ft_putunbr(n / 10);
	n = '0' + n % 10;
	write(1, &n, 1);
	return (ret + 1);
}
