/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:36 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/20 09:21:24 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lowercase(long a)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (a >= 16)
		len += ft_puthex_lowercase(a / 16);
	len += ft_putchar(base[a % 16]);
	return (len);
}
