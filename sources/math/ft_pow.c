/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:57:41 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 14:05:51 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int number, int power)
{
	int	i;
	int	result;

	if (power == 0)
		return (1);
	i = 1;
	result = number;
	while (i < power)
	{
		result = result * number;
		i++;
	}
	return (result);
}
