/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:21:43 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 13:16:19 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;
	int	tmp;

	i = 0;
	if (n > 9)
	{
		i += ft_putunsigned(n / 10);
		i += ft_putunsigned(n % 10);
	}
	else
	{
		tmp = ft_putchar(n + '0');
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	return (i);
}
