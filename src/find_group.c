/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:05:42 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/22 19:56:07 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		next_node(t_meta *d, int current)
{
	int i;
	int min_depth;
	int min_node;

	min_depth = INT_MAX;
	min_node = -1;
	i = 0;
	while (i < d->l[current].size)
	{
		if (get_link(d, d->edge_copy, current, d->l[current].rooms[i]) == -1
				&& !d->visited[d->l[current].rooms[i]]
				&& d->true_depth[d->l[current].rooms[i]] < min_depth)
		{
			min_depth = d->true_depth[d->l[current].rooms[i]];
			min_node = d->l[current].rooms[i];
		}
		i++;
	}
	if (min_node >= 0)
		return (min_node);
	return (-1);
}

int				path_size(t_meta *d)
{
	int size;
	int current_node;
	int node;

	current_node = d->end;
	size = 0;
	while ((node = next_node(d, current_node)) >= 0)
	{
		size++;
		if (node == d->start)
			return (size + 1);
		current_node = node;
	}
	return (-1);
}

static t_path	pathfinder(t_meta *d)
{
	t_path	p;
	int		node;
	int		current_node;
	int		i;

	if (!init_pathfinder(d, &p))
		return (p);
	current_node = d->end;
	i = p.size - 1;
	while ((node = next_node(d, current_node)) >= 0)
	{
		p.rooms[i] = current_node;
		if (node == d->start)
		{
			p.rooms[0] = node;
			return (p);
		}
		current_node = node;
		d->visited[node] = 1;
		i--;
	}
	p.size = 0;
	return (p);
}

static void		sort_group(t_group *g)
{
	int		i;
	int		swap;
	t_path	temp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < g->size - 1)
		{
			if (g->path_list[i].size > g->path_list[i + 1].size)
			{
				temp = g->path_list[i];
				g->path_list[i] = g->path_list[i + 1];
				g->path_list[i + 1] = temp;
				swap = 1;
			}
			i++;
		}
	}
}

t_group			find_group(t_meta *d)
{
	t_group	g;
	t_path	p;
	int		i;
	
	i = 0;
	if (!init_find_group(d, &g, &p))
		return (g);
	p = pathfinder(d);
	while (i < d->max_path && p.size > 0)
	{
		g.size++;
		ft_memcpy(&g.path_list[i], &p, sizeof(t_path));
		path_remove(d, p, d->edge_copy);
		p = pathfinder(d);
		i++;
	}
	sort_group(&g);
	return (g);
}
