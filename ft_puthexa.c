/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:59:36 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 13:00:07 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhexa(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += ft_putlhexa(num / 16);
	if ((num % 16) < 10)
		count += ft_putchar((num % 16) + '0');
	else
		count += ft_putchar((num % 16) - 10 + 'a');
	return (count);
}

int	ft_putuhexa(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += ft_putuhexa(num / 16);
	if ((num % 16) < 10)
		count += ft_putchar((num % 16) + '0');
	else
		count += ft_putchar((num % 16) - 10 + 'A');
	return (count);
}
