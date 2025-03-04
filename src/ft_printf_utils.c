/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:09 by ebella            #+#    #+#             */
/*   Updated: 2025/02/26 20:33:05 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_putchar(str[i++]);
		return (i);
	}
	return (ft_putstr("(null)"));
}

// displays n, when its between 10 and 15.
// 15 - 10 + 'a' = 'f'. hex- 'x' is for maj.
int	ft_puthex(unsigned long n, char hex)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex(n / 16, hex);
		i += ft_puthex(n % 16, hex);
	}
	else
	{
		if (n < 10)
			i += ft_putnbr(n);
		else
			i += ft_putchar(n - 10 + 'a' + (hex - 'x'));
	}
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_puthex(ptr, 'x');
	return (i);
}
