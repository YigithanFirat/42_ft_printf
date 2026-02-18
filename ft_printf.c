/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:04:01 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/18 15:37:21 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			length += format_type(args, *format);
		}
		else
			length += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (length);
}
