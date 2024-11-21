/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:10:29 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 10:03:23 by vinda-si         ###   ########.fr       */
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
	count += ft_putstr(ptr);
}

static int	ft_signal(va_list args, char signal)
{
	int count;

	count = 0;
	if (signal == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (signal == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (signal == 'p')
		count += ft_check_pointer(va_arg(args, unsigned long))
}

int	ft_printf(const char *string, ...)
{
	int		index;
	int		count;
	va_list	args;

	index = 0;
	count = 0;
	va_start (args, string);
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

