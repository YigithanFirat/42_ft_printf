/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:23:04 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 13:38:23 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_recursive(unsigned long long a)
{
	int		len;
	int		tmp;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (a >= 16)
		len += ft_putptr_recursive(a / 16);
	tmp = ft_putchar(base[a % 16]);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;
	int	tmp;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	tmp = ft_putstr("0x");
	if (tmp == -1)
		return (-1);
	len = tmp;
	tmp = ft_putptr_recursive(ptr);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}
