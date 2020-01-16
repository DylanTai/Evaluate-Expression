/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:19:38 by dtai              #+#    #+#             */
/*   Updated: 2019/08/25 23:15:53 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	int				num;
	char			opr;
	int				parent;
	int				paropr;
}				t_list;

t_list			*ft_create_elem(int num, char opr, int parent);
void			ft_list_push_back(t_list **begin_list, int num,
					char opr, int parent);
void			ft_list_clear(t_list **begin_list);
#endif
