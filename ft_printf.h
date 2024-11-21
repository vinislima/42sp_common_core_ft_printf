/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:08:15 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/21 17:42:55 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_putchar(int signal);
int	ft_printf(const char *string, ...);
int	ft_putstr(const char *string);
int	ft_putunbr(unsigned int num);
int	ft_puthexa(unsigned int num, char signal);
int	ft_putnbr(int num);
int	ft_putptr(unsigned long ptr);

#endif