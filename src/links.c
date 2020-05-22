/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:04:26 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/22 20:04:43 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_link(t_meta *d, int *matrix, int from, int to)
{
	return (matrix[to * d->room_total + from]);
}

void		add_to_link(t_meta *d, int from, int to, int val)
{
	if (d->edge_matrix[to * d->room_total + from] != val)
		d->edge_matrix[to * d->room_total + from] += val;
}

static void	zero_out_link(t_meta *d, int from, int to, int *matrix)
{
	matrix[to * d->room_total + from] = 0;
}

void		path_remove(t_meta *d, t_path p, int *matrix)
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
