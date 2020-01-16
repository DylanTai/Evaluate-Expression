/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:34:40 by dtai              #+#    #+#             */
/*   Updated: 2019/08/21 14:37:30 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *temp;
	t_list *next;

	temp = (*begin_list);
	if (*begin_list)
	{
		while (temp->next)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*begin_list = NULL;
	}
}
