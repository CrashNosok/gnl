/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahillary <ahillary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:09:39 by ahillary          #+#    #+#             */
/*   Updated: 2019/10/19 21:11:24 by ahillary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl			*new_lst_elem(int fd)
{
	t_gnl	*new;

	new = (t_gnl*)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->ream = NULL;
	new->next = NULL;
	return (new);
}

static char				*check_ream(char **ream, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (ream != '\0' && *ream != '\0')
		if ((p_n = ft_strchr(*ream, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(*ream);
			ft_strcpy(*ream, ++p_n);
		}
		else
		{
			*line = ft_strdup(*ream);
			ft_strdel(ream);
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

static int				get_line(int fd, char **line, char **ream)
{
	char			buf[BUFF_SIZE + 1];
	int				byte_was_read;
	char			*p_n;
	char			*tmp;

	if (read(fd, buf, 0))
		return (-1);
	p_n = check_ream(ream, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			*ream = ft_strdup(++p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((byte_was_read || ft_strlen(*ream) ||
			ft_strlen(*line)) ? 1 : 0);
}

int						get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || !line || BUFF_SIZE == 0 || fd > MAX_FD)
		return (-1);
	if (head == NULL)
		head = new_lst_elem(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_lst_elem(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->ream));
}
