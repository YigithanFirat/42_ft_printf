/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 01:04:01 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 20:53:14 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_f(va_list args, const char **format)
{
	int	res;

	(*format)++;
	res = format_type(args, **format);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		tmp;

	length = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			tmp = handle_f(args, &format);
		else if (*format == '%' && !*(format + 1))
			return (va_end(args), -1);
		else
			tmp = ft_putchar(*format);
		if (tmp == -1)
			return (va_end(args), -1);
		length += tmp;
		format++;
	}
	return (va_end(args), length);
}
