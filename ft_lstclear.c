/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:44:11 by Brian             #+#    #+#             */
/*   Updated: 2019/11/15 07:43:24 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*next;

	if (!(*lst) || !del)
		return ;
	cursor = *lst;
	while (cursor)
	{
		next = cursor->next;
		(*del)(cursor->content);
		free(cursor);
		cursor = next;
	}
	*lst = 0;
}
