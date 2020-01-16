# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 11:33:54 by dtai              #+#    #+#              #
#    Updated: 2020/01/16 13:11:45 by dtai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRCMC = srcs/main.c
SRCFT = srcs/ft/ft_putnbr.c srcs/ft/ft_putchar.c
SRCLI = srcs/list/ft_create_elem.c srcs/list/ft_list_push_back.c \
srcs/list/ft_list_clear.c
SRCMA = srcs/math/parenthesis.c srcs/math/mudimo.c srcs/math/adsu.c
SRCO = main.o ft_putnbr.o ft_putchar.o ft_create_elem.o ft_list_push_back.o \
ft_list_clear.o parenthesis.o mudimo.o adsu.o
INCH = includes/

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCMC) $(SRCFT) $(SRCLI) $(SRCMA) \
		-I $(INCH)
	@gcc -o $(NAME) $(SRCO)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
