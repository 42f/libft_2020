/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:26:31 by Brian             #+#    #+#             */
/*   Updated: 2020/08/28 14:34:35 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_freeable_pointer(void)
{
	return ((char *)ft_calloc(sizeof(char), 1));
}

char		*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (s_len < (size_t)start)
		return (return_freeable_pointer());
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret != NULL)
		ft_strlcpy(ret, (char *)(str + (start * sizeof(char))), len + 1);
	return (ret);
}
