# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 08:59:54 by amorion-          #+#    #+#              #
#    Updated: 2021/08/17 09:00:03 by amorion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = formats.c fromlibft.c ft_print_arg.c ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

.c.o:
	gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean: 
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: re clean fclean all bonus
