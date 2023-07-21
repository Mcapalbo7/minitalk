/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:12:34 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/03/06 21:19:39 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_hex_putnbr(unsigned int n, char *s);
int	ft_putadress(unsigned long n, char *s);
int	ft_type(const char *s, int i, va_list args);
int	ft_printf(const char *str, ...);
#endif
