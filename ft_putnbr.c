/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:58:11 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/18 16:12:46 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;
	int	tmp;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		n = -n;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	tmp = ft_putchar(n % 10 + '0');
	if (tmp == -1)
		return (-1);
	return (i + tmp);
}
