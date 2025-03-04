/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:48:48 by ebella            #+#    #+#             */
/*   Updated: 2025/02/26 21:06:19 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

int	ft_convert(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'x')
		i += ft_puthex(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		i += ft_puthex(va_arg(args, unsigned int), 'X');
	else if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putnbr(va_arg(args, unsigned int));
	else if (c == '%')
		i += ft_putchar(c);
	else if (c == 'p')
		i += ft_putptr(va_arg(args, unsigned long));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_convert(str[i++ + 1], args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
