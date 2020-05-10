/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:22:11 by Brian             #+#    #+#             */
/*   Updated: 2019/11/15 07:46:31 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenbr_fd(int c, int fd)
{
	c += '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_val;
	int				sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	n_val = n * sign;
	if (sign == -1)
		write(fd, "-", 1);
	if (n_val >= 10)
		ft_putnbr_fd(n_val / 10, fd);
	ft_writenbr_fd(n_val % 10, fd);
}
