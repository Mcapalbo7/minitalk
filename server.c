/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:03:32 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/07/21 22:27:17 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./ft_printf/ft_printf.h"

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	output;

	(void)context;
	if (signal == SIGUSR1)
		output |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (output == 0)
			kill (info->si_pid, SIGUSR2);
		ft_printf("%c", output);
		output = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	siga;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("error\n");
		exit (1);
	}
	pid = getpid();
	ft_printf("%d", pid);
	ft_printf("\n");
	siga.sa_sigaction = ft_handler;
	sigemptyset(&siga.sa_mask);
	siga.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
		pause();
	}
	return (0);
}
