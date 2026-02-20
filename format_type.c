/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:37:26 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/20 14:55:36 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_type(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, unsigned long long ));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex_lowercase(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_puthex_uppercase(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(c);
	}
	return (count);
}
