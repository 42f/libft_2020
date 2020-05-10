/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:57:47 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 08:45:46 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Code vu par fred, conseil de regrouper les conditions du if dans le while
**	mais non fonctionnel. Utilisation du break pour eviter 2 returns.
*/

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	diff = 0;
	i = 0;
	while (i < n && diff == 0)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (diff);
}
