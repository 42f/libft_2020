/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversebits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 15:06:30 by bvalette          #+#    #+#             */
/*   Updated: 2020/05/21 14:01:49 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_reversebits(unsigned int num)
{
	unsigned int count;
	unsigned int rev;

	count = sizeof(num) * 8 - 1;
	rev = num;
	num >>= 1;
	while (num)
	{
		rev <<= 1;
		rev |= num & 1;
		num >>= 1;
		count--;
	}
	rev <<= count;
	return (rev);
}
