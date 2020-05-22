/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:00:21 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/22 20:02:14 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		enlarge_links(t_meta *d, char *first, char *second)
{
	int index_a;
	int index_b;

	index_a = get_index(d, first);
	index_b = get_index(d, second);
	if (index_a >= 0 && index_b >= 0)
	{
		d->l[index_a].size++;
		d->l[index_b].size++;
	}
	else
		return (ERROR);
	return (SUCCESS);
}

static int		count_links(t_meta *d)
{
	int		i;
	char	*first;
	char	*second;
	int		links;

	links = 0;
	i = 0;
	while (d->parsing[i])
	{
		while (d->parsing[i] == '#')
			i = skip_comment(d, i);
		first = &d->parsing[i];
		if (!goto_next_c(d, &i, '-'))
			break ;
		d->parsing[i] = '\0';
		i++;
		second = &d->parsing[i];
		if (!goto_next_c(d, &i, '\n'))
			break ;
		d->parsing[i++] = '\0';
		if (!enlarge_links(d, first, second))
			break ;
		links++;
	}
	return (links);
}

static void		write_link(t_meta *d, int first, int second)
{
	d->l[first].rooms[d->l[first].index] = second;
	d->l[first].index++;
	d->l[second].rooms[d->l[second].index] = first;
	d->l[second].index++;
}

static int		read_links(t_meta *d, int links)
{
	int		i;
	char	*first;
	char	*second;

	i = 0;
	while (i < links)
	{
		while (d->parsing[0] == '#')
			d->parsing += skip_comment(d, 0);
		first = d->parsing;
		while (d->parsing[0])
			d->parsing++;
		d->parsing++;
		second = d->parsing;
		write_link(d, get_index(d, first), get_index(d, second));
		while (d->parsing[0])
			d->parsing++;
		d->parsing++;
		i++;
	}
	return (SUCCESS);
}

int				get_links(t_meta *d)
{
	int i;
	int links;

	i = 0;
	if (!(d->l = (t_links *)ft_memalloc(sizeof(t_links) * d->room_total)))
		return (ERROR);
	if ((links = count_links(d)) <= 0)
		return (ERROR);
	while (i < d->room_total)
	{
		if (!(d->l[i].rooms = (int *)ft_memalloc(sizeof(int) * d->l[i].size)))
			return (ERROR);
		i++;
	}
	if (!read_links(d, links))
		return (ERROR);
	return (SUCCESS);
}
