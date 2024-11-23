/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:43:28 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/23 11:13:53 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	// Testando conversões básicas
	int a = printf("Character: %c\n", 'A');
	int b = ft_printf("Character: %c\n", 'A');
	printf("printf = %d, ft_printf = %d\n", a, b);
	printf("\n");

	int c = printf("String: %s\n", "Hello, world!");
	int d = ft_printf("String: %s\n", "Hello, world!");
	printf("printf = %d, ft_printf = %d\n", c, d);
	printf("\n");

	int e = printf("Pointer: %p\n", (void *)42);
	int f = ft_printf("Pointer: %p\n", (void *)42);
	printf("printf = %d, ft_printf = %d\n", e, f);
	printf("\n");

	int g = printf("Integer: %d\n", 123);
	int h = ft_printf("Integer: %d\n", 123);
	printf("printf = %d, ft_printf = %d\n", g, h);
	printf("\n");

	int i = printf("Negative Integer: %d\n", -123);
	int j = ft_printf("Negative Integer: %d\n", -123);
	printf("printf = %d, ft_printf = %d\n", i, j);
	printf("\n");

	int k = printf("Unsigned: %u\n", 12345U);
	int l = ft_printf("Unsigned: %u\n", 12345U);
	printf("printf = %d, ft_printf = %d\n", k, l);
	printf("\n");
		
	int m = printf("Hex (lowercase): %x\n", 255);
	int n = ft_printf("Hex (lowercase): %x\n", 255);
	printf("printf = %d, ft_printf = %d\n", m, n);
	printf("\n");
		
	int o = printf("Hex (uppercase): %X\n", 255);
	int p = ft_printf("Hex (uppercase): %X\n", 255);
	printf("printf = %d, ft_printf = %d\n", o, p);
	printf("\n");

	// Testando casos especiais
	int q = printf("Zero: %d\n", 0);
	int r = ft_printf("Zero: %d\n", 0);
	printf("printf = %d, ft_printf = %d\n", q, r);
	printf("\n");

	int s = printf("Smallest Int: %ld\n", -2147483648);
	int t = ft_printf("Smallest Int: %d\n", -2147483648);
	printf("printf = %d, ft_printf = %d\n", s, t);
	printf("\n");

	int u = printf("Empty String: %s\n", "");
	int v = ft_printf("Empty String: %s\n", "");
	printf("printf = %d, ft_printf = %d\n", u, v);
	printf("\n");
		
	int x = printf("Null Pointer: %p\n", NULL);
	int z = ft_printf("Null Pointer: %p\n", NULL);
	printf("printf = %d, ft_printf = %d\n", x, z);
	printf("\n");

	// Testando múltiplos argumentos/conversões
	int aa = printf("Multiple: %c %s %d %u %x %X %p\n", 'A', "Test", 123, 12345U, 0xABC, 0xABC, (void *)12345);
	int ab = ft_printf("Multiple: %c %s %d %u %x %X %p\n", 'A', "Test", 123, 12345U, 0xABC, 0xABC, (void *)12345);
	printf("printf = %d, ft_printf = %d\n", aa, ab);
	printf("\n");

	// Conversões no meio de frases
	int bb = printf("This is a char: %c, and this is a string: %s.\n", 'B', "Test");
	int bc = ft_printf("This is a char: %c, and this is a string: %s.\n", 'B', "Test");
	printf("printf = %d, ft_printf = %d\n", bb, bc);
	printf("\n");

	int cc = printf("Some numbers: %d, %u, %x, %X.\n", 42, 123U, 0x1A3, 0x1A3);
	int cd = ft_printf("Some numbers: %d, %u, %x, %X.\n", 42, 123U, 0x1A3, 0x1A3);
	printf("printf = %d, ft_printf = %d\n", cc, cd);
	printf("\n");

	int dd = printf("Address: %p is a pointer.\n", (void *)0x12345);
	int dc = ft_printf("Address: %p is a pointer.\n", (void *)0x12345);
	printf("printf = %d, ft_printf = %d\n", dd, dc);
	printf("\n");

	// **Get Crazy**

	// Repetindo testes básicos com verificação de retorno
	int ee = printf("Check return: %s %d %p\n", "Hello", 42, (void *)0x123);
	int ef = ft_printf("Check return: %s %d %p\n", "Hello", 42, (void *)0x123);
	printf("printf = %d, ft_printf = %d\n", ee, ef);
	printf("\n");

	// Combinações aleatórias
	int gg = printf("Mix: %c %c %c %d %d %d %x %X %x %s\n", 'A', 'B', 'C', 1, 2, 3, 0x1, 0x2, 0x3, "End");
	int gh = ft_printf("Mix: %c %c %c %d %d %d %x %X %x %s\n", 'A', 'B', 'C', 1, 2, 3, 0x1, 0x2, 0x3, "End");
	printf("printf = %d, ft_printf = %d\n", gg, gh);
	printf("\n");

	int hh = printf("Crazy Mix: %p %ld %% %X %u\n", (void *)0, -2147483648, 0xABCDEF, 123456789U);
	int hi = ft_printf("Crazy Mix: %p %d %% %X %u\n", (void *)0, -2147483648, 0xABCDEF, 123456789U);
	printf("printf = %d, ft_printf = %d\n", hh, hi);
	printf("\n");
	
	// Séries de conversões idênticas
	int jj = printf("Repeats: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
	int jk = ft_printf("Repeats: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
	printf("printf = %d, ft_printf = %d\n", jj, jk);
	printf("\n");

	int kk = printf("Hex repeat: %x %x %x %x %x\n", 0x1, 0x2, 0x3, 0x4, 0x5);
	int kl = ft_printf("Hex repeat: %x %x %x %x %x\n", 0x1, 0x2, 0x3, 0x4, 0x5);
	printf("printf = %d, ft_printf = %d\n", kk, kl);
	printf("\n");

	int ll = printf("String repeat: %s %s %s\n", "One", "Two", "Three");
	int lm = ft_printf("String repeat: %s %s %s\n", "One", "Two", "Three");
	printf("printf = %d, ft_printf = %d\n", ll, lm);
	printf("\n");

	printf(0);
	ft_printf(0);
	printf("\n");

	int nn = printf(0);
	int no = ft_printf(0);
	printf("printf = %d, ft_printf = %d\n", nn, no);

	return (0);
}

