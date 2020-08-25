/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 07:51:38 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 10:50:46 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	retry 2 = ajout d'une protection en cas de len > haystack de strlen
**	fonctionnel = en cas de haystack bbla needle = bla
**	ajout protection si absence e haytack ou needle
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	if (haystack == NULL && needle == NULL)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		y = 0;
		while (haystack[i] == needle[y])
		{
			if (needle[y + 1] == '\0' && i < len)
				return ((char *)haystack + i - y);
			y++;
			i++;
		}
		i = i - y + 1;
		y = 0;
	}
	return (NULL);
}
