/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 07:23:13 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/12 03:11:47 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 		free_pathlist_rooms(int max_path, t_group *g)
{
	int i;

	i = 0;
	while (i < max_path)
	{
		free(g->path_list[i].rooms);
		i++;
	}
}

int		free_meta(t_meta *d)
{	
	int i;

	i = 0;
	free(d->og_parsing);
	free(d->room_name);
	while(i < d->room_total && d->l)
	{
		free(d->l[i].rooms);
		i++;
	}
	free(d->depth);
	free(d->visited);
	free(d->prev);
	free(d->edge_matrix);
	free(d->edge_copy);
	free(d->l);
	free(d->queue.q);
	if (d->best.path_list)	
		free_pathlist_rooms(d->max_path, &d->best);
	free(d->best.path_list);
	return (0);
}

