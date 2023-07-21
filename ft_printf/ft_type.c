/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:51:07 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/03/06 19:18:52 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *s, int i, va_list args)
{
	int	t;

	t = 0;
	if (s[i] == 'c')
		t += ft_putchar((char) va_arg(args, int));
	else if (s[i] == 's')
		t += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		t += ft_putnbr(va_arg(args, int));
	else if (s[i] == 'u')
		t += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (s[i] == 'p')
		t += ft_putadress(va_arg(args, unsigned long), "0123456789abcdef");
	else if (s[i] == 'x')
		t += ft_hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[i] == 'X')
		t += ft_hex_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s[i] == '%')
		t += ft_putchar('%');
	return (t);
}
