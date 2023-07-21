/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:58:49 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/03/07 17:02:53 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + 48);
	return (i);
}
