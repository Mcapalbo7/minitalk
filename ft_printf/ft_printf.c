/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:00:25 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/03/06 21:27:29 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(p, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			l += ft_type(str, i + 1, p);
			i++;
		}
		else
		{
			l += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(p);
	return (l);
}
