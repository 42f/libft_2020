/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:27:27 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 14:48:10 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_is_valid(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			if (base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static void	ft_putnum(unsigned long long int n, char *base)
{
	n = base[n];
	write(1, &n, 1);
}

void		ft_putnbr_base(long long int nbr, char *base)
{
	unsigned long long	nosign;
	unsigned int		b_size;

	nosign = 0;
	b_size = 0;
	while (base[b_size])
		b_size++;
	if (b_size <= 1)
		return ;
	if (ft_is_valid(base) == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nosign = -nbr;
		}
		else
			nosign = nbr;
		if (nosign >= b_size)
			ft_putnbr_base(nosign / b_size, base);
	}
	ft_putnum(nosign % b_size, base);
}
