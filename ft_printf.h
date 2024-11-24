/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:08:15 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 19:26:54 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// o arquivo ft_printf.h contem os protótipos das 
// funções que serão utilizadas nesse projeto.
// inicioamos com a a condição #ifnder que verifica se a
// constante FT_PRINTF_H não foi definida, caso não tenha sido
// definida, define a constante e executa o código abaixo.
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// inclui a biblioteca stdarg.h que contém as funções para manipulação
// de argumentos variáveis.
# include <stdarg.h>

int	ft_putchar(int signal);
int	ft_printf(const char *string, ...);
int	ft_putstr(const char *string);
int	ft_putunbr(unsigned int num);
int	ft_puthexa(unsigned int num, char signal);
int	ft_putnbr(int num);
int	ft_putptr(unsigned long ptr);
// ao final do arquivo, fechamos a condição #ifndef
// com a condição #endif
#endif