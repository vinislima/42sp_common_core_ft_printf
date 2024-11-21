/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:34:12 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 18:04:57 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *string);

int	ft_putstr(const char *string)
{
	int	count;

	count = 0;
	if (!string)
		string = "(null)";
	while (string[count] != '\0')
	{
		ft_putchar(string[count]);
		count++;
	}
	return (count);
}
