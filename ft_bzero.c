/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:39:50 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 11:44:36 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = use of ft_memset instead of a loop
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
