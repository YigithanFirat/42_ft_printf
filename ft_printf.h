/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:42:28 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/05 21:05:06 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	format_type(va_list args, char c);
int	ft_putnbr(int n);
int	ft_putptr(unsigned long long ptr);
int	ft_puthex(unsigned int n, char format);
int	ft_printf(const char *format, ...);
int	ft_putunsigned(unsigned int n);

#endif
