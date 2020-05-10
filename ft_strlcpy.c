/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:10:49 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 08:35:09 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	RETRY = Usage de ft_strlen pour la src pour plus de clarté
**	instabilité par rapport a fonction de la libc = si le buffer
**	réélement malloc pour dst est inferieur a dstsize = abort a l'ecriture
**	de dst[i].
**	size_t pour size_src
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			size_src;

	i = 0;
	if (!dst || !src)
		return (0);
	size_src = ft_strlen(src);
	if (dstsize == 0)
		return (size_src);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
