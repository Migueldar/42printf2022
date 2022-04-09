/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 05:44:54 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/03/27 05:46:57 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int caps)
{
	int	ret;

	if (n < 16)
	{
		n += '0';
		if (n >= 10 + '0')
		{
			n += 'a' - 10 - '0';
			if (caps)
				n += 'A' - 'a';
		}
		write(1, &n, 1);
		return (1);
	}
	ret = ft_puthex(n / 16, caps);
	if (n % 16 >= 10)
	{
		n = 'a' - 10 + n % 16;
		if (caps)
			n += 'A' - 'a';
	}
	else
		n = '0' + n % 16;
	write(1, &n, 1);
	return (ret + 1);
}

int	ft_putptr(unsigned long n)
{
	int				counter;
	unsigned long	div;

	write(1, "0x", 2);
	counter = 2;
	div = 1;
	while (n / div > 15)
		div *= 16;
	while (div)
	{
		ft_puthex((n / div) % 16, 0);
		div /= 16;
		counter++;
	}		
	return (counter);
}
