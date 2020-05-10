/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:50:16 by Brian             #+#    #+#             */
/*   Updated: 2019/11/20 08:00:38 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	retry = cast void * du malloc
**  RETRY 2 = utilisation de calloc_size pour gerer le count == 0
**  et eviter de bzero un null.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_ptr;
	size_t	alloc_size;

	alloc_size = count * size;
	new_ptr = malloc(alloc_size);
	if (new_ptr != NULL)
		ft_bzero(new_ptr, alloc_size);
	return (new_ptr);
}
