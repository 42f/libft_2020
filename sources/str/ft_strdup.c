/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:38:39 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 14:45:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	RETRY = Ajout de parentheses dans le malloc englobant (strlen + 1)
**  retry 2 = suggestion Fred usage de strlen 1 seule fois
*/

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	dst = malloc(sizeof(char) * (len_s1 + 1));
	if (dst != NULL)
		ft_memcpy(dst, s1, len_s1 + 1);
	return (dst);
}
