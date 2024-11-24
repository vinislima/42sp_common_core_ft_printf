/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:59 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 21:29:52 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inclui o arquivo ft_printf.h que contém os protótipos das funções
#include "ft_printf.h"
// a função ft_putnbr recebe um número inteiro e retorna a quantidade de caracteres impressos.
int	ft_putnbr(int num);

int	ft_putnbr(int num)
{
	// declaramos um array de char de tamanho 11
	// para armazenar o número convertido para char,
	// dois inteiros um para contar a quantidade de caracteres
	// e outro para armazenar o índice do array, além de um long
	// para armazenar o número durante a conversão.
	char	buffer[11];
	int		count;
	int		index;
	long	number;
	// inicializamos o contador e o índice com 0
	// e o número com o valor recebido.
	count = 0;
	number = num;
	// se o número for menor que 0
	if (num < 0)
	{
		// incrementamos o contador com a quantidade de caracteres impressos
		// pelo ft_putchar que imprime o caractere '-' e convertemos o número
		// para positivo, para continuar a conversão.
		count += ft_putchar('-');
		number = -number;
	}
	// inicializamos o índice com 0
	index = 0;
	// se o número for 0, armazenamos '0' no array e incrementamos o índice
	if (number == 0)
		// armazenamos '0' no array e incrementamos o índice
		buffer[index++] = '0';
	// se o número for maior que 0, entramos no laço
	while (number > 0)
	{
		// armazenamos o resto da divisão por 10 + '0' no array
		// dessa forma, convertemos o número para char
		buffer[index++] = (number % 10) + '0';
		// dividimos o número por 10 para continuar a conversão
		// até que o número seja 0
		number /= 10;
	}
	// enquanto o índice for maior ou igual a 0
	// decrementamos o índice e incrementamos o contador
	// dessa forma imprimimos o número convertido para char
	// em ordem reversa.
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	// retornamos a quantidade de caracteres impressos ao final da função.
	return (count);
}
