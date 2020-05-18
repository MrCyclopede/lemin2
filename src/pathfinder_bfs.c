/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_bfs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:12:46 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/18 17:02:06 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	reverse_path(t_path *p)
{
	int swap;
	int i;
	int j;

	i = 0;
	j = p->size - 1;
	while (i < j)
	{
		swap = p->rooms[i];
		p->rooms[i] = p->rooms[j];
		p->rooms[j] = swap;
		i++;
		j--;
	}
}

static int	next_node(t_meta *d, int node)
{
	int i;

	i = 0;
	while (i < d->room_total)
	{
		if ((get_link(d, d->edge_copy, node, i) == 1) && !d->visited[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	bfs(t_meta *d)
{
	int current_node;
	int	node;

	d->visited[d->start] = 1;
	add_queue(d, d->start);
	while ((current_node = queue_next(d)) >= 0)
	{
		while ((node = next_node(d, current_node)) >= 0)
		{
			d->prev[node] = current_node;
			d->depth[node] = d->depth[current_node] + 1;
			if (node == d->end)
				return (path_len(d));
			add_queue(d, node);
			d->visited[node] = 1;
		}
	}
	return (0);
}

static void	init_bfs(t_meta *d, t_path *p)
{
	reset_queue(d);
	ft_bzero(p, sizeof(t_path));
	ft_bzero(d->depth, sizeof(int) * d->room_total);
	ft_bzero(d->prev, sizeof(int) * d->room_total);
	ft_bzero(d->visited, sizeof(int) * d->room_total);
}

t_path		pathfinder_bfs(t_meta *d)
{
	t_path	p;
	int		i;
	int		node;

	init_bfs(d, &p);
	p.size = bfs(d);
	if (p.size)
	{
		if (!(p.rooms = (int *)ft_memalloc(sizeof(int) * p.size)))
		{
			p.size = 0;
			return (p);
		}
		i = 0;
		node = d->end;
		while (i < p.size)
		{
			p.rooms[i] = node;
			node = d->prev[node];
			i++;
		}
		p.rooms[i] = d->start;
	}
	reverse_path(&p);
	return (p);
}
