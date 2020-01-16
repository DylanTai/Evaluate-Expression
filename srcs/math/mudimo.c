/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mudimo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:39:11 by dtai              #+#    #+#             */
/*   Updated: 2019/08/25 21:34:31 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*calcmdm(t_list *first, t_list *second, t_list *third)
{
	int result;

	if (second->opr == '*')
		result = second->num * third->num;
	else if (second->opr == '/')
		result = second->num / third->num;
	else if (second->opr == '%')
		result = second->num % third->num;
	if (first)
	{
		third->num = result;
		free(second);
		first->next = third;
		return (first);
	}
	second->num = result;
	second->opr = third->opr;
	second->next = third->next;
	second->paropr = third->paropr;
	free(third);
	return (second);
}

int		legalmdm(char opr)
{
	if (opr == '*' || opr == '/' || opr == '%')
		return (1);
	return (0);
}

void	mudimo(t_list **equation, int p)
{
	t_list	*curr;
	t_list	*prev;
	int		dns;

	prev = 0;
	curr = *equation;
	while (curr && curr->next)
	{
		dns = 0;
		if (curr->parent == p && curr->next->parent == p && legalmdm(curr->opr)
				&& (curr->paropr == curr->parent || curr->paropr == -1))
		{
			if (prev == 0)
				dns = 1;
			curr = calcmdm(prev, curr, curr->next);
		}
		if (!dns)
		{
			prev = curr;
			curr = curr->next;
		}
		else if (!(curr->next))
			break ;
	}
}
