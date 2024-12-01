# ft_printf

This project is a custom implementation of the `printf` function in C, named `ft_printf`. The goal is to replicate the functionality of the standard `printf` function, which formats and prints data to the standard output. The project is organised into several `.c` files, each implementing a specific function, and a header file (`ft_printf.h`) that contains the declarations of these functions. A Makefile is provided to facilitate the compilation of the project.

The project provides a modular and well-organised implementation of the `ft_printf` function, with each auxiliary function handling a specific type of data. The use of separate `.c` files for each function and a centralised header file (`ft_printf.h`) ensures clarity and maintainability. The Makefile simplifies the compilation process, ensuring that all dependencies are correctly managed.

### **File Structure**

- **`ft_printf.h`**: Header file with declarations of functions used in `ft_printf`.
    - Contains the declarations of all functions used in `ft_printf`, including `ft_putchar`, `ft_printf`, `ft_putstr`, `ft_putunbr`, `ft_puthexa`, `ft_putnbr`, and `ft_putptr`.
- **`ft_printf.c`**: Main implementation of the `ft_printf` function.
    - The main function that processes the format string and arguments. It identifies format specifiers and calls the corresponding auxiliary functions to handle each type of data.
- **`ft_putchar.c`**: Function to print a character.
    - Prints a single character to the standard output using the Unix `write` function. It takes an integer (character) as an argument and returns 1 after printing.
- **`ft_puthexa.c`**: Function to print a hexadecimal number.
    - Prints an unsigned integer in hexadecimal format. Uses a buffer to store the characters before printing them to the standard output.
- **`ft_putnbr.c`**: Function to print an integer.
    - Prints an integer. Handles negative numbers and uses a buffer to store the characters before printing them to the standard output.
- **`ft_putptr.c`**: Function to print a pointer.
    - Prints a pointer in hexadecimal format. Uses a buffer to store the characters before printing them to the standard output.
- **`ft_putstr.c`**: Function to print a string.
    - Prints a string. Handles null strings by printing "(null)" to the standard output.
- **`ft_putunbr.c`**: Function to print an unsigned number.
- **Makefile**: Script to compile the project.
    - Defines the rules to compile `.c` files into `.o` files and create the `libftprintf.a` library. Includes rules to clean object files (`clean`), clean all files (`fclean`), and recompile everything (`re`).

---

## **Usage**

Uncomment the main, use `make` in the terminal and use the command below.

```
cc -Wall -Wextra -Werror main.c libftprintf.a
```

---

- Files:
    - [ft_printf.c](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_printf.c):
        
        ```c
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
        
        ```
        
    - [ft_printf.h](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_printf.h):
        
        ```c
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
        ```
        
    - [ft_putchar.c](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_putchar.c):
        
        ```c
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
        
        ```
        
    - [ft_puthexa.c](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_puthexa.c):
        
        ```c
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
        
        ```
        
    - [ft_putnbr.c](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_putnbr.c):
        
        ```c
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
        
        ```
        
    - [ft_putptr](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_putptr.c):
        
        ```c
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
        
        ```
        
    - [ft_putstr](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_putstr.c):
        
        ```c
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
        
        ```
        
    - [ft_putunbr.c](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/ft_putunbr.c):
        
        ```c
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
        
        ```
        
    - [main.c](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/main.c):
        
        ```c
        /* ************************************************************************** */
        /*                                                                            */
        /*                                                        :::      ::::::::   */
        /*   main.c                                             :+:      :+:    :+:   */
        /*                                                    +:+ +:+         +:+     */
        /*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
        /*                                                +#+#+#+#+#+   +#+           */
        /*   Created: 2024/11/22 14:43:28 by vinda-si          #+#    #+#             */
        /*   Updated: 2024/11/23 20:59:48 by vinda-si         ###   ########.fr       */
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
        
        	int i = printf("Negative Integer: %i\n", -123);
        	int j = ft_printf("Negative Integer: %i\n", -123);
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
        	int aa = printf("Multiple: %c %s \n", 'A', "Test");
        	int ab = ft_printf("Multiple: %c %s \n", 'A', "Test");
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
        
        ```
        
    - [Makefile](https://github.com/vinislima/42sp_common_core_ft_printf/blob/main/Makefile):
        
        ```c
        # **************************************************************************** #
        #                                                                              #
        #                                                         :::      ::::::::    #
        #    Makefile                                           :+:      :+:    :+:    #
        #                                                     +:+ +:+         +:+      #
        #    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
        #                                                 +#+#+#+#+#+   +#+            #
        #    Created: 2024/11/24 15:32:16 by vinda-si          #+#    #+#              #
        #    Updated: 2024/11/30 21:52:35 by vinda-si         ###   ########.fr        #
        #                                                                              #
        # **************************************************************************** #
        
        # Define the name of the library
        NAME = libftprintf.a
        # Define the source files
        SRCS =	ft_printf.c \
        		ft_putchar.c \
        		ft_putstr.c \
        		ft_putunbr.c \
        		ft_puthexa.c \
        		ft_putnbr.c \
        		ft_putptr.c \
        # Define the object files to be created
        # The object files are the source files
        # with the .c replaced with .o
        OBJS = $(SRCS:.c=.o)
        # Define the compiler
        # The compiler is cc
        CC = cc
        # Define the remove command
        # The remove command is rm -f
        # The -f flag is used to avoid errors
        # if the files do not exist
        RM = rm -f
        # Define the flags to be passed to the compiler
        # The flags are -Wall -Wextra -Werror
        # The -Wall flag is used to turn on most of the compiler warnings
        # The -Wextra flag is used to turn on extra compiler warnings
        # The -Werror flag is used to turn the warnings into errors
        CFLAGS = -Wall -Wextra -Werror
        # Define the rules
        # The rules are all, clean, fclean, re
        # The all rule is the default rule
        all: $(NAME)
        # NAME is the dependency of the all rule
        # If NAME is not up to date, the rule is executed
        # The rule compiles the object files and creates the library
        $(NAME): $(OBJS)
        # The rule is executed by the following command
        # The command is ar rcs $(NAME) $(OBJS)
        # The command creates the library $(NAME) with the object files $(OBJS)
        # The command is executed by the following steps
        %.o: %.c ft_printf.h
        	$(CC) $(CFLAGS) -c $< -o $@
        	ar rcs $(NAME) $@
        # The clean rule deletes the object files
        clean:
        		$(RM) $(OBJS)
        # The fclean rule deletes the object files and the library
        fclean: clean
        		$(RM) $(NAME)
        # The re rule is used to recompile the program
        re: fclean $(NAME)
        # The .PHONY rule is used to avoid conflicts with files
        .PHONY: all clean fclean re
        ```