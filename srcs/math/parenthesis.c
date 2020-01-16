/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:30:43 by dtai              #+#    #+#             */
/*   Updated: 2019/08/25 23:19:50 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "math.h"
#include <stdlib.h>

void	parent_check(t_list **equation, int p)
{
	t_list *curr;

	curr = *equation;
	while (curr)
	{
		if (curr->parent == p)
			curr->parent -= 1;
		curr = curr->next;
	}
}

void	do_math(t_list **equation, int p)
{
	while (p >= 0)
	{
		mudimo(equation, p);
		adsu(equation, p);
		parent_check(equation, p);
		p--;
	}
}

void	fix_equation(t_list **equation)
{
	t_list *curr;
	t_list *temp;

	curr = *equation;
	while (curr && curr->next)
	{
		if (curr->opr == '\0')
		{
			curr->opr = curr->next->opr;
			temp = curr->next;
			curr->next = temp->next;
			curr->paropr = temp->parent;
			free(temp);
		}
		curr = curr->next;
	}
}

int		find_highest_parent(t_list **equation)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = *equation;
	while (curr)
	{
		if (curr->parent > i)
			i = curr->parent;
		curr = curr->next;
	}
	return (i);
}

void	parenthesis(t_list **equation)
{
	int p;

	p = find_highest_parent(equation);
	fix_equation(equation);
	do_math(equation, p);
}
