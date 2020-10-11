/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:23:22 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/10 07:15:17 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

static void		ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->content);
	free(lst);
	lst = NULL;
}

void			ft_lstclear(t_list **lst)
{
	t_list		*buf;

	if (!lst)
		return ;
	while (*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = buf;
	}
}
