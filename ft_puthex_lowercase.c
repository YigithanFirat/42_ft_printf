/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:36 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/20 14:21:34 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lowercase(unsigned int a)
{
	int		len;
	char	*base;
	int		tmp;

	len = 0;
	base = "0123456789abcdef";
	if (a >= 16)
	{
		tmp = ft_puthex_lowercase(a / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar(base[a % 16]);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}
