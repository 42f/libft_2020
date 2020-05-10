/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:31:39 by Brian             #+#    #+#             */
/*   Updated: 2019/11/19 07:39:05 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = changements pour clarifier les if, voir fichier diff
*/

static int		ft_word_count(char const *s, char sep)
{
	int	i;
	int	wc;
	int	s_len;

	s_len = (int)ft_strlen(s);
	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i] != sep && s[i + 1] == sep)
			wc++;
		else if (s[i] != sep && i + 1 == s_len)
			wc++;
		i++;
	}
	return (wc);
}

static size_t	wdlen(char const *s, char sep)
{
	int	len;

	len = 0;
	if (s[0] != sep)
	{
		while (s[len] != sep && s[len] != '\0')
			len++;
	}
	else if (s[0] == sep)
	{
		while (s[len] == sep && s[len] != '\0')
			len++;
	}
	return (len);
}

static char		**ft_free_return(char **r, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i <= n)
	{
		free(r[i]);
		i++;
	}
	free(r);
	return (NULL);
}

static char		**ft_el_spliter(char **r, char const *s, char c, int wc)
{
	int		i;
	int		y;
	int		s_len;

	i = 0;
	y = 0;
	s_len = (int)ft_strlen(s);
	while (i < wc && y < s_len)
	{
		if (s[y] == c)
			y = y + wdlen(s + y, c);
		if (!(r[i] = (char*)malloc(sizeof(char *) * (wdlen(s + y, c) + 1))))
			return (ft_free_return(r, i));
		ft_strlcpy(r[i], s + y, wdlen(s + y, c) + 1);
		y = y + wdlen(s + y, c);
		i++;
	}
	r[wc] = NULL;
	return (r);
}

char			**ft_split(char const *s, char c)
{
	char	**r;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	if (!(r = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	return (ft_el_spliter(r, s, c, wc));
}
