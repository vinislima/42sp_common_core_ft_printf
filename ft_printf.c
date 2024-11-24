/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:10:29 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 18:34:37 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// incluindo a biblioteca ft_printf.h para
// ter acessos as funções que estão no arquivo
#include "ft_printf.h"  
// declarando a função ft_printf que recebe
// uma string e uma lista de argumentos variáveis
// e retorna um inteiro, que é a quantidade de
// caracteres que foram impressos.
int			ft_printf(const char *string, ...);
// declarando a função ft_signal que recebe
// uma lista de argumentos variáveis e um caractere
// e retorna um inteiro, que é a quantidade de
// caracteres que foram impressos, nessa função
// é feito um switch case para verificar qual
// caractere foi passado e chama a função correspondente
static int	ft_signal(va_list args, char signal);

static int	ft_signal(va_list args, char signal)
{
	// declarando a variável count do tipo inteiro
	// que será utilizada para contar a quantidade
	// de caracteres que foram impressos
	int	count;
	// inicializando a variável count com 0
	count = 0;
	// verificando qual caractere foi passado
	// e chamando a função correspondente
	// incrementando a variável count com o retorno
	// da função correspondente
	if (signal == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (signal == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (signal == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (signal == 'd' || signal == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (signal == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (signal == 'x' || signal == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), signal);
	else if (signal == '%')
		count += ft_putchar('%');
	// retornando a quantidade de caracteres que foram impressos
	return (count);
}

int	ft_printf(const char *string, ...)
{
	// declarando as variáveis index e count do tipo inteiro
	// e a variável args do tipo va_list que será utilizada
	// para armazenar a lista de argumentos variáveis
	int		index;
	int		count;
	va_list	args;
	// inicializando as variáveis index e count com 0
	// e a variável args com a lista de argumentos variáveis
	index = 0;
	count = 0;
	va_start (args, string);
	// verificando se a string é nula
	// e retornando -1 caso seja
	if (!string)
		return (-1);
	// enquanto a string não for nula
	// verifica se o caractere atual é igual a '%'
	// se for chama a função ft_signal passando
	// a lista de argumentos variáveis e o próximo
	// caractere da string, incrementando a variável
	while (string[index] != '\0')
	{
		if (string[index] == '%')
		{
			count += ft_signal(args, string[index + 1]);
			index++;
		}
		else
			// se o caractere atual não for igual a '%'
			// incrementa a variável count com o retorno
			// da função ft_putchar passando o caractere atual
			count += ft_putchar(string[index]);
		// incrementando a variável index
		// para passar para o próximo caractere
		index++;
	}
	// finalizando a lista de argumentos variáveis
	// e retornando a quantidade de caracteres que foram impressos
	va_end (args);
	return (count);
}
