/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:13:25 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/25 17:21:22 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = Segfault trouvé ! La protection contre !set n'existait pas
** et permetait de segfault ft_is_set
*/

static int	ft_is_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		i;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_is_set(s1[i], set) == 1)
		i++;
	while (len > i && ft_is_set(s1[len], set) == 1)
		len--;
	if (!(r = (char *)ft_calloc(sizeof(char), len - i + 2)))
		return (NULL);
	ft_strlcpy(r, s1 + i, len - i + 2);
	return (r);
}
