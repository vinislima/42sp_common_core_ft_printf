/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:03:01 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 13:07:11 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_putunbr(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}
