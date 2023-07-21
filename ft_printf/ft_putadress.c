/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:49:11 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/03/06 22:12:46 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress_last(unsigned long n, char *s)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_putadress_last(n / 16, s);
	i += ft_putchar(s[n % 16]);
	return (i);
}

int	ft_putadress(unsigned long n, char *s)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_putadress_last(n, s);
	return (i);
}
