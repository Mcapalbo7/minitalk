/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:31:31 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/07/21 22:27:42 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	ft_catchint(int signal)
{
	if (signal == SIGUSR2)
		ft_printf ("message received\n");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * sign);
}

void	bithandler(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Number of parametres invalid");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		exit(1);
	while (argv[2][++i] != '\0')
	{
		bithandler(argv[2][i], pid);
	}
	signal(SIGUSR2, ft_catchint);
	bithandler('\0', pid);
	return (0);
}
