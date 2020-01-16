/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:21:18 by dtai              #+#    #+#             */
/*   Updated: 2019/08/25 13:59:03 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(int num, char opr, int parent)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->next = 0;
	list->num = num;
	list->opr = opr;
	list->parent = parent;
	list->paropr = -1;
	return (list);
}
