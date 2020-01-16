/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 23:32:34 by dtai              #+#    #+#             */
/*   Updated: 2019/08/25 23:14:13 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_list.h"
#include "math.h"

int		g_parenthesis;

char	*parse_num2(char *str, t_list **equation, int sign, int num)
{
	char opr;

	opr = '\0';
	if (sign == -1)
		num = num * -1;
	if (*str != '\0' && *str != ')')
	{
		opr = *str;
		str++;
	}
	ft_list_push_back(equation, num, opr, g_parenthesis);
	while (*str == ')')
	{
		g_parenthesis--;
		str++;
	}
	return (str);
}

char	*parse_num(char *str, t_list **equation)
{
	int sign;
	int num;

	sign = 1;
	num = 0;
	while (*str == '(' || *str == ' ' || (*str >= '0' && *str <= '9')
			|| *str == '-')
	{
		if (*str == '(')
			g_parenthesis++;
		if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
			sign = -1;
		else if (*str == '-')
			break ;
		if (num == 214748364 && sign == -1 && *str == '8')
		{
			sign = 1;
			num = -2147483648;
			break ;
		}
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		str++;
	}
	return (parse_num2(str, equation, sign, num));
}

int		eval_expr(char *str)
{
	t_list	**equation;
	t_list	*temp;
	int		answer;

	g_parenthesis = 0;
	temp = 0;
	equation = malloc(sizeof(t_list *));
	*equation = temp;
	while (*str != '\0')
		str = parse_num(str, equation);
	parenthesis(equation);
	answer = 0;
	if (*equation != 0)
		answer = (*equation)->num;
	ft_list_clear(equation);
	return (answer);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
