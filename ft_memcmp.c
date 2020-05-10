/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:31:45 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 11:12:44 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
**	Rety = changement DE ++i PAR i < n - 1 puis i++; proprement
**  retry 2 = changement i < n - 1 par i + 1 < n pour ne pas donner  p1[i]
**  la possibilité de sortir.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i + 1 < n && p1[i] == p2[i])
		i++;
	return ((int)(p1[i] - p2[i]));
}
