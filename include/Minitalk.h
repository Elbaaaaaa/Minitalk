/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:48:51 by ebella            #+#    #+#             */
/*   Updated: 2025/04/17 19:12:43 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <unistd.h>

extern int	g_ack_received;

int		ft_putchar(char c);
int		ft_puthex(unsigned long n, char hex);
int		ft_putstr(char *str);
int		ft_putnbr(long int nb);
int		ft_convert(const char c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_putptr(unsigned long ptr);
int		ft_atoi(const char *str);
void	send_char(int pid, char c);
void	sig_handler(int sig, siginfo_t *info, void *context);

#endif
