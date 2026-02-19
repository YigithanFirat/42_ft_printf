/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:28:50 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/18 19:35:39 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_uppercase(unsigned int a)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789ABCDEF";
	if (a >= 16)
		len += ft_puthex_uppercase(a / 16);
	len += ft_putchar(base[a % 16]);
	return (len);
}