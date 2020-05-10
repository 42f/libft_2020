/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 15:15:51 by bvalette          #+#    #+#             */
/*   Updated: 2020/04/05 15:30:42 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_swapendian(unsigned int num)
{
	int	first;
	int	second;
	int	third;
	int	last;

	first = ((num & 0x000000FF)) << 24;
	second = ((num & 0x0000FF00) >> 8) << 16;
	third = ((num & 0x00FF0000) >> 16) << 8;
	last = ((num & 0xFF000000) >> 24);

	return (first | second | third | last);
}
