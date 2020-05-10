/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2020/01/16 14:45:25 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		*get_skipped_input(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

long long int			ft_atoi(const char *str)
{
	int			output;
	size_t		i;

	output = 0;
	i = 0;
	str = get_skipped_input(str);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		output = output * 10 + (str[i++] - 48);
	return (str[0] == '-' ? -output : output);
}
