/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:43:51 by tkleiner          #+#    #+#             */
/*   Updated: 2020/10/04 05:44:11 by tkleiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*buf;

	if (!lst)
		return (NULL);
	buf = lst;
	while (buf->next)
		buf = buf->next;
	return (buf);
}

t_list		*ft_lstnew(void *content, int id, int color)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	new->id = id;
	new->color = color;
	return (new);
}

void		ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (!new || !lst)
		return ;
	buf = ft_lstlast(*lst);
	if (buf)
		buf->next = new;
	else
		*lst = new;
}
