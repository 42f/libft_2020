/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 10:06:22 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/19 07:31:06 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = usage de calloc a la place de malloc pour assurer la bonne
**	null termination de r si strlcpy faisait defaut.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(r = (char *)ft_calloc(sizeof(char), (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strlcpy(r, s1, len_s1 + len_s2 + 1);
	ft_strlcpy(r + len_s1, s2, len_s1 + len_s2 + 1);
	return (r);
}
