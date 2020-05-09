/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:05:42 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/12 03:11:46 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		next_node(t_meta *d, int current)
{
	int i;

	i = 0;
	while (i < d->room_total)
	{
		if (get_link(d, d->edge_copy, current, i) == 1)
			return (i);
		i++;
	}
	return (-1);
}

static int		path_size(t_meta *d)
{
	int size;
	int current_node;
	int node;

	current_node = d->start;
	size = 0;
	while ((node = next_node(d, current_node)) >= 0)
	{
		size++;
		if (node == d->end)
			return (size + 1);
		current_node = node;
	}
	return (-1);
}

static t_path 		pathfinder(t_meta *d)
{
	t_path p;
	int node;
	int current_node;
	int i;


	ft_bzero(&p, sizeof(t_path));
	if ((p.size = path_size(d)) < 0)
		return (p);
	if (!(p.rooms = (int *)ft_memalloc(sizeof(int) * p.size)))
	{
		p.size = 0;
		return (p);
	}
	current_node = d->start;
	i = 0;
	while ((node = next_node(d, current_node)) >= 0)
	{	
		p.rooms[i] = current_node;
		if (node == d->end)
		{
			p.rooms[i + 1] = node;
			return (p);
		}
		current_node = node;
		i++;
	}
	p.size = 0;
	return (p);
}

static void	sort_group(t_group *g)
{
	int i;
	int swap;
	t_path temp;

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
				g->path_list[i] = g->path_list[i +1];
				g->path_list[i +1] = temp;
				swap = 1;
			}
			i++;
		}
	}
}


static int init_find_group(t_meta *d, t_group *g, t_path *p)
{
	(void)d;
	ft_bzero(g, sizeof(t_group));
	if(!(g->path_list = (t_path *)ft_memalloc(sizeof(t_path) * d->max_path)))
		return (ERROR);
	ft_bzero(p, sizeof(t_path));
	ft_bzero(d->edge_copy, sizeof(int) * (d->room_total * d->room_total));
	ft_memcpy(d->edge_copy, d->edge_matrix, sizeof(int) 
			* (d->room_total * d->room_total));
	return (SUCCESS);
}

t_group find_group(t_meta *d)
{
	t_group g;
	t_path p;
	int i;

	i = 0;
	if (!init_find_group(d, &g, &p))
		return (g);
	p = pathfinder(d);
	while (i < d->max_path && p.size > 0)
	{
		g.size ++;
		ft_memcpy(&g.path_list[i], &p, sizeof(t_path));
		path_remove(d, p, d->edge_copy);
		p = pathfinder(d);
		i++;
	}
	sort_group(&g);
	return (g);
}
