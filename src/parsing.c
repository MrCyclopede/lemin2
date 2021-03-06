/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:37:41 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/18 08:38:19 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_index(t_meta *d, char *room)
{
	int i;

	i = 0;
	while (i < d->room_total)
	{
		if (!ft_strcmp(d->room_name[i], room))
			return (i);
		i++;
	}
	return (-1);
}

int		get_ants(t_meta *d)
{
	while (d->parsing[0] == '#')
	{
		while (d->parsing[0] && d->parsing[0] != '\n')
			d->parsing++;
		d->parsing++;
	}
	d->ant_total = ft_atoi(d->parsing);
	if (d->ant_total <= 0)
		return (ERROR);
	while (d->parsing[0] && ft_isdigit(d->parsing[0]))
		d->parsing++;
	if (d->parsing[0] != '\n')
		return (ERROR);
	else
		d->parsing++;
	return (SUCCESS);
}

int		parsing(t_meta *d)
{
	int len;

	len = 0;
	if (!(d->parsing = read_file()))
		return (ERROR);
	else
		d->og_parsing = d->parsing;
	len = ft_strlen(d->parsing);
	if (!(d->parsing_cpy = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(d->parsing_cpy, d->parsing, sizeof(char) * len);
	if (!get_ants(d))
		return (ERROR);
	if (!get_rooms(d))
		return (ERROR);
	if (d->start < 0 || d->end < 0)
		return (ERROR);
	if (!get_links(d))
		return (ERROR);
	d->max_path = d->l[d->start].size;
	if (d->room_total >= QUEUE_SIZE)
		return (ERROR);
	return (SUCCESS);
}
