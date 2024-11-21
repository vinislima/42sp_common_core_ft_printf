/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:00:25 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 13:01:04 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int		count;
	long	number;

	count = 0;
	number = num;
	if (num < 0)
	{
		count += ft_putchar('-');
		number *= -1;
	}
	if (number >= 10)
		count += ft_putnbr(number / 10);
	count += ft_putchar((number % 10) + '0');
	return (count);
}
