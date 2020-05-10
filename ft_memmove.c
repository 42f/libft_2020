/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:28:48 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 11:42:08 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** RETRY = typage des pointeurs unsigned char a la place de char
** retry 2 = ajout d'une protection si dst ou src null et simplification du
** while : utlisation du if sur src et dst qui ne bougent pas pour
** determiner le sens
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	size_t			i;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (src < dst)
			p_dst[len - 1 - i] = p_src[len - 1 - i];
		else
			p_dst[i] = p_src[i];
		i++;
	}
	return (p_dst);
}
