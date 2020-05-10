/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:47:20 by Brian             #+#    #+#             */
/*   Updated: 2019/11/19 07:45:08 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = Version corrigée pour eviter le double ajout du premier elements !
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cursor;

	if (!lst || !f || !del)
		return (NULL);
	ret = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		if (!(cursor = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, cursor);
		lst = lst->next;
	}
	return (ret);
}
