/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:44 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 21:57:09 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inclui o arquivo ft_printf.h que contém os protótipos das funções
#include "ft_printf.h"
// a função ft_putptr recebe um número inteiro sem sinal
// do tipo unsigned long e retorna a quantidade de caracteres impressos.
int	ft_putptr(unsigned long ptr);

int	ft_putptr(unsigned long ptr)
{
	// declaramos um array de char de tamanho 8
	// para armazenar o número convertido para hexadecimal
	// e dois inteiros um para contar a quantidade de caracteres
	// impressos e outro para armazenar o índice do array.
	char	buffer[8];
	int		count;
	int		index;
	// inicializamos o contador e o índice com 0
	count = 0;
	index = 0;
	// se o número for 0, passamos a string "(nil)" para ft_putstr
	// diretamente e retornamos a quantidade de caracteres impressos
	// pois a função ft_putstr já retorna a quantidade de caracteres impressos.
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	// se não, incrementamos o contador com a quantidade de caracteres impressos
	// passando a '0' e 'x' para ft_putchar separadamente.
	count += ft_putchar('0');
	count += ft_putchar('x');
	// enquanto o número for maior que 0
	// entramos no laço
	while (ptr > 0)
	{
		// se o resto da divisão do número por 16 for menor que 10
		if ((ptr % 16) < 10)
			// armazenamos o resto da divisão + '0' no array
			// dessa forma, convertemos o número para char
			buffer[index++] = (ptr % 16) + '0';
		else
			// caso contrário, armazenamos o resto da divisão - 10 + 'a'
			// no array, dessa forma, convertemos o número para char
			buffer[index++] = (ptr % 16) - 10 + 'a';
		// dividimos o número por 16
		// para continuar a conversão
		// até que o número seja 0
		ptr /= 16;
	}
	// decrementamos o índice para acessar o último elemento do array
	// e decrementamos o contador para acessar o último caractere impresso
	// e incrementamos o contador com a quantidade de caracteres impressos
	// passando o array de char para ft_putchar.
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	// retornamos a quantidade de caracteres impressos
	return (count);
}
