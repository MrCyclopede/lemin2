/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 06:37:13 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/12 03:11:47 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void 	init_depth_bfs(t_meta *d)
{
	ft_bzero(d->true_depth, sizeof(int) * (d->room_total));
	ft_bzero(d->visited, sizeof(int) * (d->room_total));
	reset_queue(d);	
}

static int next_node(t_meta *d, int current_node)
{
	int i;
	
	i = 0;
	while (i < d->l[current_node].size)
	{
		if (d->visited[d->l[current_node].rooms[i]] == 0)
			return (d->l[current_node].rooms[i]);
		i++;
	}
	return (-1);
}

void 	depth_bfs(t_meta *d)
{
	int node;
	int current_node;
	
	init_depth_bfs(d);
	add_queue(d, d->start);
	d->visited[d->start] = 1;
	while ((current_node = queue_next(d)) >= 0)	
	{
		if (current_node == d->end)
			continue;
		while ((node = next_node(d, current_node)) >= 0)
		{		
			add_queue(d, node);
			d->visited[node] = 1;
			d->true_depth[node] = d->true_depth[current_node] + 1;
			
		}
	}
}
