/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:22:11 by Brian             #+#    #+#             */
/*   Updated: 2019/12/29 10:34:07 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenbr(int c)
{
	c += '0';
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	unsigned int	n_val;
	int				sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	n_val = n * sign;
	if (sign == -1)
		write(1, "-", 1);
	if (n_val >= 10)
		ft_putnbr(n_val / 10);
	ft_writenbr(n_val % 10);
}
