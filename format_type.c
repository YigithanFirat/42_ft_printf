/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:37:26 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 21:00:44 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_type_numbers(va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	return (0);
}

int	format_type(va_list args, char c)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(args, int));
	else if (c == 's')
		res = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		res = ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		res = format_type_numbers(args, c);
	else if (c == '%')
		res = ft_putchar('%');
	else
	{
		if (ft_putchar('%') == -1)
			return (-1);
		res = ft_putchar(c);
		if (res != -1)
			res += 1;
	}
	return (res);
}
