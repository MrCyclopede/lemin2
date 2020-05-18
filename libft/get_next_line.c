/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 04:22:33 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/18 18:29:29 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_fresh_link(int fd, t_line **begin_list)
{
	t_line	*link;

	link = NULL;
	if (!(link = (t_line*)ft_memalloc(sizeof(t_line))))
		return (NULL);
	link->next = *begin_list;
	link->fd = fd;
	*begin_list = link;
	return (link);
}

t_line	*ft_search_fd(int fd, t_line **begin_list, int o)
{
	t_line	*tmp;

	tmp = *begin_list;
	if (o == 0)
	{
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		return (ft_fresh_link(fd, begin_list));
	}
	if (o == 1)
	{
		while (*begin_list)
		{
			if (0 <= (*begin_list)->fd)
				return (NULL);
			begin_list = &(*begin_list)->next;
		}
		return (*begin_list);
	}
	return (NULL);
}

t_line	*ft_free_link(t_line **link, t_line **begin_list)
{
	t_line	*tmp;

	tmp = *begin_list;
	(*link)->fd = -1;
	if (!(ft_search_fd((*link)->fd, begin_list, 1)))
		return (NULL);
	while (tmp->next != *begin_list)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	return (NULL);
}

int		gnl(t_line *link, char **line, char *buff)
{
	char	*stock;

	link->tmp = ft_strjoin2(link->tmp, buff);
	stock = link->tmp;
	link->ln = ft_strretri(link->tmp, '\n', ft_strlen(link->tmp));
	if (link->ln == NULL)
		ft_strdel(&link->ln);
	if (link->ln)
	{
		if (link->ar)
			link->ln = ft_strjoinfree(&link->ar, &link->ln, 3);
		link->tmp = ft_strdup(ft_strchr(link->tmp, '\n') + 1);
		ft_strdel(&stock);
		if (!(ft_strchr(link->tmp, '\n')))
			link->ar = ft_strjoinfree(&link->ar, &link->tmp, 3);
		*line = ft_strdup(link->ln);
		ft_strdel(&link->ln);
		return (1);
	}
	link->ar = ft_strjoinfree(&link->ar, &link->tmp, 3);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_line	*begin_list = NULL;
	t_line			*link;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || FOPEN_MAX <= fd || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!begin_list)
		begin_list = ft_fresh_link(fd, &begin_list);
	link = ft_search_fd(fd, &begin_list, 0);
	while ((0 < (ret = read(fd, buff, BUFF_SIZE))) || (link->tmp))
	{
		buff[ret] = '\0';
		if (gnl(link, line, buff))
			return (1);
	}
	if (ret == -1)
		return (-1);
	if ((link->ar && (ft_strlen(link->ar))) && (*line = ft_strdup(link->ar)))
	{
		ft_strdel(&link->ar);
		return (1);
	}
	ft_free_link(&link, &begin_list);
	return (0);
}
