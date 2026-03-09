/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:33:03 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 20:53:06 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	char	*base;
	int		len;
	int		tmp;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	tmp = ft_putchar(base[n % 16]);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}
