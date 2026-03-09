/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:37:26 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/20 15:35:19 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_type_numbers(va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	return (0);
}

int	format_type(va_list args, char c)
{
	int	tmp;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (format_type_numbers(args, c));
	if (c == '%')
		return (ft_putchar('%'));
	if (ft_putchar('%') == -1)
		return (-1);
	tmp = ft_putchar(c);
	if (tmp == -1)
		return (-1);
	return (tmp + 1);
}
