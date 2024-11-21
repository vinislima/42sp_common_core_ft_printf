/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:10:29 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 18:05:23 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *string, ...);
static int	ft_signal(va_list args, char signal);
static int	ft_check_pointer(unsigned long ptr);

static int	ft_check_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putptr(ptr);
	return (count);
}

static int	ft_signal(va_list args, char signal)
{
	int	count;

	count = 0;
	if (signal == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (signal == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (signal == 'p')
		count += ft_check_pointer(va_arg(args, unsigned long));
	else if (signal == 'd' || signal == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (signal == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (signal == 'x' || signal == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), signal);
	else if (signal == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		index;
	int		count;
	va_list	args;

	index = 0;
	count = 0;
	va_start (args, string);
	if (!string)
		return (-1);
	while (string[index] != '\0')
	{
		if (string[index] == '%')
		{
			count += ft_signal(args, string[index + 1]);
			index++;
		}
		else
			count += ft_putchar(string[index]);
		index++;
	}
	va_end (args);
	return (count);
}
