# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 14:51:43 by vinda-si          #+#    #+#              #
#    Updated: 2024/11/23 22:09:58 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## declaramos o nome do arquivo que será gerado
## neste caso, libftprintf.a
NAME = libftprintf.a
## declaramos os arquivos que serão compilados
## neste caso, todos os arquivos .c
SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_puthexa.c \
		ft_putnbr.c \
		ft_putptr.c \
## declaramos os arquivos .o que serão gerados
## a partir dos arquivos .c
OBJS = $(SRCS:.c=.o)
## declaramos o compilador
CC = cc
## declaramos o comando para remover arquivos
RM = rm -f
## declaramos as flags de compilação
CFLAGS = -Wall -Wextra -Werror
## declaramos as flags de linkagem
all: $(NAME)
## declaramos a regra para compilar os arquivos .c
## e gerar os arquivos .o
$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)
## declaramos a regra para remover os arquivos .o
clean:
		$(RM) $(OBJS)
## declaramos a regra para remover os arquivos
## .o e o arquivo gerado
fclean: clean
		$(RM) $(NAME)
## declaramos a regra para recompilar o projeto
re: fclean $(NAME)
## declaramos as palavras reservadas
## para que o make não confunda com arquivos
.PHONY: all clean fclean re