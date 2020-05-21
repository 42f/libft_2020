/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:19:03 by bvalette          #+#    #+#             */
/*   Updated: 2020/05/21 14:06:26 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static int	ft_read(int fd, t_gnl_l *ft_curs, t_gnl_l *read_buffer_head)
{
	int				ret;
	t_gnl_l			*buff;

	if (read_buffer_head != NULL && read_buffer_head->ct[0] == '\0')
		buff = read_buffer_head;
	else
	{
		read_buffer_head->next = ft_create_node(-1, NULL);
		buff = read_buffer_head->next;
	}
	ret = 1;
	while (ret > 0)
	{
		if (buff == NULL || (ret = read(fd, buff->ct, BUFFER_SIZE)) < 0)
			return (-1);
		buff->ct[ret] = '\0';
		if (ft_gnl_strchr(buff->ct, '\n') != NULL)
			break ;
		buff->next = ft_create_node(-1, NULL);
		buff = buff->next;
	}
	ft_strlcpy(ft_curs->ct, ft_gnl_strchr(buff->ct, '\n'), BUFFER_SIZE);
	if (ret <= BUFFER_SIZE && ret > 0)
		ret = 1;
	return (ret);
}

static int	ft_write_line(char **line, t_gnl_l *read_buffer_head)
{
	size_t			dst_size;
	size_t			buff_len;
	t_gnl_l			*cursor;

	cursor = read_buffer_head;
	buff_len = 0;
	while (cursor != NULL)
	{
		cursor = cursor->next;
		buff_len++;
	}
	dst_size = BUFFER_SIZE * buff_len + 1;
	if ((*line = (char *)malloc(sizeof(char) * (dst_size + 1))) == NULL)
		return (-1);
	*line[0] = '\0';
	while (read_buffer_head != NULL)
	{
		ft_gnl_strlcat(*line, read_buffer_head->ct, dst_size);
		if (read_buffer_head->fd < 0)
			read_buffer_head = read_buffer_head->next;
		else
			break ;
	}
	return (1);
}

static int	ft_gnl_from_fd(int fd, char **line, t_gnl_l *ft_curs)
{
	int				ret;
	t_gnl_l			*read_buffer_head;
	t_gnl_l			*next;

	ret = 0;
	if (BUFFER_SIZE <= 0)
	{
		*line = (char *)malloc(sizeof(char));
		return (-1);
	}
	read_buffer_head = ft_create_node(-1, ft_curs->ct);
	if (read_buffer_head == NULL)
		return (-1);
	ret = ft_read(fd, ft_curs, read_buffer_head);
	if (ft_write_line(line, read_buffer_head) == -1)
		ret = -1;
	while (read_buffer_head != NULL)
	{
		next = read_buffer_head->next;
		free(read_buffer_head->ct);
		free(read_buffer_head);
		read_buffer_head = next;
	}
	free(read_buffer_head);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	int				ret;
	static	t_gnl_l	*fd_head;
	t_gnl_l			*ft_curs;

	if (line == NULL)
		return (-1);
	ret = -1;
	if (fd_head == NULL)
		if ((fd_head = ft_create_node(fd, NULL)) == NULL)
			return (-1);
	ft_curs = ft_lst_manager(fd_head, fd);
	if (ft_curs != NULL && ft_gnl_strchr(ft_curs->ct, '\n') != NULL)
	{
		if ((ret = ft_write_line(line, ft_curs)) == -1)
			return (-1);
		ft_strlcpy(ft_curs->ct, ft_gnl_strchr(ft_curs->ct, '\n'), BUFFER_SIZE);
	}
	else if (ft_curs != NULL)
		ret = ft_gnl_from_fd(fd, line, ft_curs);
	if (ret < 1)
		fd_head = ft_free_fd_cursor(fd_head, fd);
	return (ret);
}
