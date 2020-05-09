/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:04:26 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/02/23 10:07:42 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	get_link(t_meta *d, int *matrix, int from, int to)
{
	return (matrix[to * d->room_total + from]);
}

static void	add_to_link(t_meta *d, int from, int to, int val)
{
	d->edge_matrix[to * d->room_total + from] += val;
}

static void	zero_out_link(t_meta *d, int from, int to, int *matrix)
{
	matrix[to * d->room_total + from] = 0;
}

void path_remove(t_meta *d, t_path p, int *matrix)
{
	int i;

	i = 0;
	while (i < p.size - 1)
	{
		zero_out_link(d, p.rooms[i], p.rooms[i + 1], matrix);
		zero_out_link(d, p.rooms[i + 1], p.rooms[i], matrix);
		i++;
	}
}

int		path_update(t_meta *d, t_path p)
{
	int i;

	i = 0;
	if (p.size <= 0)
		return (ERROR);
	while (i < p.size - 1)
	{
		add_to_link(d, p.rooms[i], p.rooms[i + 1], -1);
		add_to_link(d, p.rooms[i + 1], p.rooms[i], 1);
		i++;
	}
	return (SUCCESS);
}

int path_len(t_meta *d)
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
