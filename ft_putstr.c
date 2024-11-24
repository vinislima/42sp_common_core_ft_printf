/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:34:12 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 21:58:28 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inclui o arquivo ft_printf.h que contém os protótipos das funções
#include "ft_printf.h"
// a função ft_putstr recebe uma string do tipo char
int	ft_putstr(const char *string);

int	ft_putstr(const char *string)
{
	// declaramos um inteiro para contar a quantidade de caracteres
	int	count;

	count = 0;
	// se a string for nula, passamos "(null)" para ft_putstr
	if (!string)
		string = "(null)";
	// enquanto o caractere for diferente de '\0'
	while (string[count] != '\0')
	{
		// passamos o caractere para ft_putchar
		ft_putchar(string[count]);
		// incrementamos o contador
		count++;
	}
	// ao final, retornamos a quantidade de caracteres impressos
	return (count);
}
