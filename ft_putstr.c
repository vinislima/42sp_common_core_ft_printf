/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:22:41 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/20 21:40:16 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *string);

int	ft_putstr(const char *string)
{
	int count;

	count = 0;
	if (!string)
		string = "(null)";
	while (string != '\0')
	{
		ft_putchar(string[count]);
		count++;
	}
	return (count);
}