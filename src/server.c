/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:16:02 by ebella            #+#    #+#             */
/*   Updated: 2025/03/04 11:16:19 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minitalk.h"

void	sig_handler(int sig)
{
	static int bit;
	static int i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

void	sig_recieved(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Signal recieved\n");
}

int	main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}