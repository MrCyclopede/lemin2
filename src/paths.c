/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:03:02 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/22 20:04:41 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			path_update(t_meta *d, t_path p)
{
	int i;

	i = 0;
	if (p.size <= 0)
	{
		free(p.rooms);
		p.rooms = 0;
		return (ERROR);
	}
	while (i < p.size - 1)
	{
		d->depth[p.rooms[i]] = d->tmp_depth[p.rooms[i]];
		add_to_link(d, p.rooms[i], p.rooms[i + 1], -1);
		add_to_link(d, p.rooms[i + 1], p.rooms[i], 1);
		i++;
	}
	free(p.rooms);
	return (SUCCESS);
}

int			path_len(t_meta *d)
{
	int i;
	int node;

	i = 0;
	node = d->end;
	while (node != d->start)
	{
		node = d->prev[node];
		i++;
	}
	return (i + 1);
}
