/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 07:23:13 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/12 03:11:47 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		eval_group(t_meta *d, t_group g)
{
	int s;

	s = steps(d, g);
	if (s < 0)
	{ 
		free_pathlist_rooms(d->max_path, &g);	
		free(g.path_list);
		return (ERROR);
	}
	else if (s < d->best.steps && s > 0) // >= si je veux pas split ?
	{
		if (d->best.path_list)
		{
			free_pathlist_rooms(d->max_path, &d->best);
			free(d->best.path_list);
		}
		ft_memcpy(&d->best, &g, sizeof(t_group));
		d->best.steps = s;
	}
	else
	{	
		free_pathlist_rooms(d->max_path, &g);
		free(g.path_list);
		return (ERROR);
	}
	return (SUCCESS);
}

int	init_solution(t_meta *d)
{
	int i;

	ft_bzero(&d->best, sizeof(t_group)); // superflu ? 
//	if (!(d->best.path_list
//				= (t_path *)ft_memalloc(sizeof(t_path) * d->max_path)))
//		return (ERROR);
	d->best.steps = INT_MAX;
	if (!create_queue(d))
		return (ERROR);
	if (!(d->edge_matrix = (int *)ft_memalloc(sizeof(int)
					* (d->room_total * d->room_total))))
		return (ERROR);
	if (!(d->edge_copy = (int *)ft_memalloc(sizeof(int)
					* (d->room_total * d->room_total))))
		return (ERROR);
	if (!(d->depth = (int *)ft_memalloc(sizeof(int) * d->room_total)))
		return (ERROR);
	if (!(d->tmp_depth = (int *)ft_memalloc(sizeof(int) * d->room_total)))
		return (ERROR);

	if (!(d->true_depth = (int *)ft_memalloc(sizeof(int) * d->room_total)))
		return (ERROR);

	if (!(d->visited = (int *)ft_memalloc(sizeof(int) * d->room_total)))
		return (ERROR);
	if (!(d->prev = (int *)ft_memalloc(sizeof(int) * d->room_total)))
		return (ERROR);
	i = 0;
	while(i < d->room_total)
	{
		d->depth[i] = INT_MAX;
		i++;
	}
	d->depth[d->start] = 0;
	return (SUCCESS);
}

int	solve(t_meta *d)
{
	int threshold;

	threshold = 0;
	if (!init_solution(d))
		return (ERROR);
		
	depth_bfs(d);	
	while (path_update(d, first_pass_bfs(d)))
	{	
	
		if (!eval_group(d, find_group(d)))
		{
			threshold++;
			//if (threshold > 100)	
			//	break;
		}
		
	}
	if (!d->best.size)
		return (ERROR);
	return (SUCCESS);
}
