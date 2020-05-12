/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pass_bfs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:01:20 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/02/23 11:27:02 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


static int	next_node(t_meta *d, int node)
{
	int i;
			
	i = 0;
	while (i < d->l[node].size)
	{
		if (!d->visited[d->l[node].rooms[i]]
				&& (get_link(d, d->edge_matrix, node, d->l[node].rooms[i]) <= 0))
		{
			return (d->l[node].rooms[i]);
		}
		i++;
	}
	return (-1);
}
static int bfs(t_meta *d)
{
	int current_node;
	int	node;

	d->visited[d->start] = 1;
	d->depth[d->start] = 0;
	add_queue(d, d->start);
	while ((current_node = queue_next(d)) >= 0)
	{	
		while ((node = next_node(d, current_node)) >= 0)
		{
			d->prev[node] = current_node;
			if (get_link(d, d->edge_matrix, node, current_node) == 0)
				d->depth[node] = d->depth[current_node] + 1;
			else
				d->depth[node] = d->depth[current_node] - 1;
			if (node == d->end)
				return (path_len(d));
			add_queue(d, node);
			d->visited[node] = 1;
		}
	}
	return (0); //should never happen 
}

static int	init_bfs(t_meta *d, t_path *p)
{
	int i;
	
	ft_bzero(p, sizeof(t_path));
	i = 0;
	while(i < d->room_total)
	{
		d->depth[i] = INT_MAX;
		i++;
	}
	reset_queue(d);
	ft_bzero(d->prev, sizeof(int) * d->room_total);
	ft_bzero(d->visited, sizeof(int) * d->room_total);
	return (SUCCESS);
}

t_path first_pass_bfs(t_meta *d)
{	
	int i;
	int node;
	t_path p;

	init_bfs(d, &p);
	p.size = bfs(d);
	if (p.size)
	{
		if (!(p.rooms = (int *)ft_memalloc(sizeof(int) * (p.size + 1))))
		{
			p.size = 0;
			return (p);
		}
		i = 0;
		node = d->end;
		while (i < p.size)
		{
			p.rooms[i] = node;
			node = d->prev[node]; // remonte
			i++;
		}
		p.rooms[i] = d->start;
	}
	return (p); 
}
