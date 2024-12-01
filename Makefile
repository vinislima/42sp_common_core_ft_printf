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