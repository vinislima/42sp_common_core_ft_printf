/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:44 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 17:39:43 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr);

int	ft_putptr(unsigned long ptr)
{
	char	buffer[16];
	int		count;
	int		index;

	count = 0;
	index = 0;
	if (ptr == 0)
		return (ft_putchar('0'));
	while (ptr > 0)
	{
		if ((ptr % 16) < 10)
			buffer[index++] = (ptr % 16) + '0';
		else
			buffer[index++] = (ptr % 16) - 10 + 'a';
		ptr /= 16;
	}
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	return (count);
}
