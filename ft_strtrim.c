/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:13:25 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/19 07:46:26 by bvalette         ###   ########.fr       */
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
	int		y;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	y = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_is_set(s1[i], set) == 1)
		i++;
	while (y > i && ft_is_set(s1[y], set) == 1)
		y--;
	if (!(r = (char *)ft_calloc(sizeof(char), y - i + 2)))
		return (NULL);
	ft_strlcpy(r, s1 + i, y - i + 2);
	return (r);
}
