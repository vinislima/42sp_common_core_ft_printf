/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:30:28 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 22:02:22 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inclui o arquivo ft_printf.h que contém os protótipos das funções
#include "ft_printf.h"
// a função ft_putunbr recebe um número inteiro sem sinal
int	ft_putunbr(unsigned int num);

int	ft_putunbr(unsigned int num)
{
	// declaramos um array de char de tamanho 10
	// para armazenar o número convertido para char
	// e dois inteiros um para contar a quantidade de caracteres
	// impressos e outro para armazenar o índice do array.
	char	buffer[10];
	int		count;
	int		index;
	// inicializamos o contador e o índice com 0
	count = 0;
	index = 0;
	// se o número for 0, passamos '0' para o buffer
	if (num == 0)
		buffer[index++] = '0';
	// enquanto o número for maior que 0
	while (num > 0)
	{
		// armazenamos o resto da divisão do número por 10 + '0' no array
		// dessa forma, convertemos o número para char
		buffer[index++] = (num % 10) + '0';
		// dividimos o número por 10 para continuar a conversão
		// até que o número seja 0
		num /= 10;
	}
	// decrementamos o índice para acessar o último elemento do array
	// e decrementamos o contador para acessar o último caractere impresso
	// e incrementamos o contador com a quantidade de caracteres impressos
	// passando o caractere para ft_putchar separadamente.
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	// ao final, retornamos a quantidade de caracteres impressos
	return (count);
}
