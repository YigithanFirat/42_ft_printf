/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:42:28 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/15 18:57:39 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf_char(int c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	format_type(va_list args, char c);
int	ft_putnbr(int n);

#endif
