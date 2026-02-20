/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:23:04 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/20 09:23:43 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex_lowercase(ptr);
	return (len);
}
