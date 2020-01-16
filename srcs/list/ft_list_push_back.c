/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:46:38 by dtai              #+#    #+#             */
/*   Updated: 2019/08/25 15:57:25 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, int num, char opr, int parent)
{
	t_list *temp;

	temp = *begin_list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_create_elem(num, opr, parent);
	}
	else
		*begin_list = ft_create_elem(num, opr, parent);
}
