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

static int	handle_printf(va_list args, const char **format)
{
	int	tmp;

	if (**format == '%' && *(*format + 1))
	{
		(*format)++;
		tmp = format_type(args, **format);
	}
	else if (**format == '%' && !*(*format + 1))
		tmp = -1;
	else
		tmp = ft_putchar(**format);
	return (tmp);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		temp_length;

	if (!format)
		return (-1);
	length = 0;
	va_start(args, format);
	while (*format)
	{
		temp_length = handle_printf(args, &format);
		if (temp_length == -1)
			return (-1);
		length += temp_length;
		format++;
	}
	va_end(args);
	return (length);
}
