/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:37:42 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 21:25:45 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inclui o arquivo ft_printf.h que contém os protótipos das funções
#include "ft_printf.h"
// a função ft_puthexa recebe um número inteiro sem sinal e um caractere
// que pode ser 'x' ou 'X' e retorna a quantidade de caracteres impressos.
int	ft_puthexa(unsigned int num, char signal);

int	ft_puthexa(unsigned int num, char signal)
{
	// declaramos um array de char de tamanho 8
	// para armazenar o número convertido para hexadecimal
	// e dois inteiros um para contar a quantidade de caracteres
	// impressos e outro para armazenar o índice do array.
	char	buffer[16];
	int		count;
	int		index;
	// inicializamos o contador e o índice com 0
	count = 0;
	index = 0;
	// se o número for 0, armazenamos '0' no array e incrementamos o índice
	if (num == 0)
		buffer[index++] = '0';
	// se o numero for maior que 0, entramos no laço
	// caso contrário, o laço não será executado.
	while (num > 0)
	{
		// se o resto da divisão do número por 16 for menor que 10
		if ((num % 16) < 10)
			// armazenamos o resto da divisão + '0' no array
			// dessa forma, convertemos o número para char
			buffer[index++] = (num % 16) + '0';
		// caso contrário, armazenamos o resto da divisão - 10 + 'a' ou 'A'
		// no array, dessa forma, convertemos o número para char
		else
		{
			// se o sinal for 'x', armazenamos o resto da divisão - 10 + 'a'
			// convertendo o número para char minúsculo
			if (signal == 'x')
				buffer[index++] = (num % 16) - 10 + 'a';
			// caso contrário, armazenamos o resto da divisão - 10 + 'A'
			// convertendo o número para char maiúsculo
			else
				buffer[index++] = (num % 16) - 10 + 'A';
		}
		// dividimos o número por 16
		// para continuar a conversão
		// até que o número seja 0
		num /= 16;
	}
	// decrementamos o índice para acessar o último caractere
	// para o primeiro caractere do número convertido para hexadecimal
	// e incrementamos o contador para contar a quantidade de caracteres
	// impressos.
	while (--index >= 0)
		// imprimimos o caractere e incrementamos o contador
		count += ft_putchar(buffer[index]);
	// retornamos a quantidade de caracteres impressos
	return (count);
}
