/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:58:49 by ebella            #+#    #+#             */
/*   Updated: 2025/04/20 13:01:02 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minitalk.h"

int		g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		while (!g_ack_received)
			pause();
		usleep(500);
		g_ack_received = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR2, ack_handler);
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
	else
	{
		ft_printf("./client [server_pid] [message]\n");
		return (1);
	}
	return (0);
}
