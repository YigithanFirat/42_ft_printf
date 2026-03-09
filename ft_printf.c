/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:04:01 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/20 13:38:32 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	if (!*format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			length += format_type(args, *format);
		}
		else if (*format == '%' && !*(format + 1))
			return (-1);
		else
			length += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (length);
}
