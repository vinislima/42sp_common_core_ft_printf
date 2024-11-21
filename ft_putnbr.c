/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:59 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 18:03:09 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num);

int	ft_putnbr(int num)
{
	char	buffer[11];
	int		count;
	int		index;
	long	number;

	count = 0;
	number = num;
	if (num < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	index = 0;
	if (number == 0)
		buffer[index++] = '0';
	while (number > 0)
	{
		buffer[index++] = (number % 10) + '0';
		number /= 10;
	}
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	return (count);
}
