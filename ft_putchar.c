/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:32:15 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 20:54:01 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// incluindo a biblioteca unistd.h para
// ter acesso a função write
#include <unistd.h>
// declarando a função ft_putchar que recebe
// um inteiro e retorna um inteiro
int	ft_putchar(int signal);

int	ft_putchar(int signal)
{
	// chamando a função write que escreve
	// o caractere passado como argumento
	// no descritor de arquivo 1 (stdout),
	// e utilizamos o & para passar o endereço
	// do caractere para a função write
	write(1, &signal, 1);
	// ao final da função retornamos 1
	return (1);
}
