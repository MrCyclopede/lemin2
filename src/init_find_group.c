/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_find_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:05:42 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/22 19:48:13 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_pathfinder(t_meta *d, t_path *p)
{
	ft_bzero(p, sizeof(t_path));
	if ((p->size = path_size(d)) < 0)
	{
		p->size = 0;
		return (ERROR);
	}
	if (!(p->rooms = (int *)ft_memalloc(sizeof(int) * p->size)))
	{
		p->size = 0;
		return (ERROR);
	}
	return (SUCCESS);
}

int		init_find_group(t_meta *d, t_group *g, t_path *p)
{
	ft_bzero(g, sizeof(t_group));
	if (!(g->path_list = (t_path *)ft_memalloc(sizeof(t_path) * d->max_path)))
		return (ERROR);
	ft_bzero(p, sizeof(t_path));
	ft_bzero(d->visited, sizeof(int) * d->room_total);
	ft_bzero(d->edge_copy, sizeof(int) * (d->room_total * d->room_total));
	ft_memcpy(d->edge_copy, d->edge_matrix, sizeof(int)
			* (d->room_total * d->room_total));
	return (SUCCESS);
}
