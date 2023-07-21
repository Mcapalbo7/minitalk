/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:22:11 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/03/06 22:16:14 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_putnbr(unsigned int n, char *s)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_hex_putnbr(n / 16, s);
	i += ft_putchar(s[n % 16]);
	return (i);
}
