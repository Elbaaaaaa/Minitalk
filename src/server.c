/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:16:02 by ebella            #+#    #+#             */
/*   Updated: 2025/03/31 14:49:28 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minitalk.h"

void sig_handler(int sig, siginfo_t *info, void *context)
{
	static int bit = 0;
	static int i = 0;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int main(int argc, char **argv)
{
	int pid;
	struct sigaction act;

	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (0);
	}
	(void)argv;
	act.sa_sigaction = sig_handler;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
