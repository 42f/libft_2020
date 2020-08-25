/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:40 by bvalette          #+#    #+#             */
/*   Updated: 2020/05/21 14:05:14 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

t_gnl_l	*ft_free_fd_cursor(t_gnl_l *fd_head, int fd)
{
	t_gnl_l			*fd_cursor;
	t_gnl_l			*fd_next;

	fd_cursor = fd_head;
	fd_next = fd_cursor;
	while (fd_next != NULL)
	{
		if (fd_next->fd != fd)
		{
			fd_cursor = fd_next;
			fd_next = fd_cursor->next;
			continue ;
		}
		if (fd_next == fd_head)
			fd_head = fd_next->next;
		else
			fd_cursor->next = fd_next->next;
		free(fd_next->ct);
		free(fd_next);
		break ;
	}
	return (fd_head);
}

t_gnl_l	*ft_create_node(int new_fd, char *ct)
{
	t_gnl_l			*new_node;
	int				i;

	new_node = (t_gnl_l *)malloc(sizeof(t_gnl_l));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = new_fd;
	new_node->next = NULL;
	new_node->ct = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new_node->ct == NULL)
		return (NULL);
	i = 0;
	if (ct != NULL)
		ft_strlcpy(new_node->ct, ct, BUFFER_SIZE + 1);
	else
	{
		while (i < BUFFER_SIZE + 1)
		{
			new_node->ct[i] = '\0';
			i++;
		}
	}
	return (new_node);
}

t_gnl_l	*ft_lst_manager(t_gnl_l *cursor, int fd_to_find)
{
	while (cursor != NULL)
	{
		if (cursor->fd == fd_to_find)
			return (cursor);
		if (cursor->next != NULL)
			cursor = cursor->next;
		else
			break ;
	}
	cursor->next = ft_create_node(fd_to_find, NULL);
	return (cursor->next);
}

size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_len;
	size_t			src_len;
	size_t			ret;
	int				i;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	ret = src_len + dst_len;
	while (dst_len < dstsize - 1 && src[i] != '\0' && src[i] != '\n')
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (ret);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i + 1));
		i++;
	}
	return (NULL);
}
