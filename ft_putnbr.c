/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:58:11 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 20:52:49 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n > 9)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar(n % 10 + '0');
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}
