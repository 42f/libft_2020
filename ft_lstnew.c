/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:23:27 by Brian             #+#    #+#             */
/*   Updated: 2019/11/15 07:46:20 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r;

	if (!(r = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	r->content = content;
	r->next = NULL;
	return (r);
}
