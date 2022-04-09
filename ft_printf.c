/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 03:40:36 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/03/27 18:14:41 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	which_option(char option, va_list *lst)
{
	if (option == 'c')
		return (ft_putchar(va_arg(*lst, int)));
	else if (option == 's')
		return (ft_putstr(va_arg(*lst, const char *)));
	else if (option == 'p')
		return (ft_putptr((unsigned long) va_arg(*lst, void *)));
	else if (option == 'd' || option == 'i')
		return (ft_putnbr(va_arg(*lst, int)));
	else if (option == 'u')
		return (ft_putunbr(va_arg(*lst, unsigned int)));
	else if (option == 'x')
		return (ft_puthex(va_arg(*lst, unsigned int), 0));
	else if (option == 'X')
		return (ft_puthex(va_arg(*lst, unsigned int), 1));
	else if (option == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	iter;
	int		counter;	

	va_start(iter, str);
	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			counter += which_option(*(str + 1), &iter);
			str++;
		}
		else
		{
			write(1, str, 1);
			counter++;
		}
		if (*str)
			str++;
	}
	va_end(iter);
	return (counter);
}
