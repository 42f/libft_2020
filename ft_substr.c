/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:26:31 by Brian             #+#    #+#             */
/*   Updated: 2019/11/19 07:46:30 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = retrait du cast de r sur le return en cas de strlen < start
**	retrait cast de s dans str_len inutil
**	retrait dernier condition s_len < start car jamais utilisée
**	calloc pour remplacer malloc + bzero
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < (size_t)start)
	{
		if (!(r = (char *)ft_calloc(sizeof(char), 1)))
			return (NULL);
		return (r);
	}
	if (!(r = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(r, (char *)(s + start), len + 1);
	return (r);
}
