/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 05:16:18 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/02/22 03:26:05 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


static void	move_ant(t_meta *d, t_ant *a, int ant)
{
	a->room_index++;
	if (a->room_index  >= a->path->size)
		return ;
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(d->room_name[a->path->rooms[a->room_index]]);
	ft_putchar(' ');
}

static void	sender(t_meta *d, t_ant *a)
{
	int round;
	int ant;

	round = 0;
	while (round < d->best.steps)
	{
		ant = 0;
		while (ant < d->ant_total)
		{
			if (round >= a[ant].send_round)
				move_ant(d, &a[ant], ant + 1);
			ant++;
		}
		ft_putchar('\n');
		round++;	
	}
}
static void	division(t_meta *d, t_ant *ant_list)
{
	int i;
	int ant;
	int round;

	ant = 0;
	round = 0;
	while (ant < d->ant_total)
	{	
		while (d->best.size > 0 && round > d->best.path_list[d->best.size - 1].stop)
			d->best.size--;
		i = 0;
		while ((i < d->best.size || !i) && ant < d->ant_total)
		{
			ant_list[ant].path = &d->best.path_list[i];
			ant_list[ant].send_round = round;
			i++;
			ant++;
		}			
		round++;
	}
}


static void	assign_path(t_meta *d, t_ant *a)
{
	int i;
	
	i = 0;
	while (i < d->best.size)
	{
		d->best.path_list[i].stop = d->best.steps - (d->best.path_list[i].size - 1);
		i++;
	}
	division(d, a);
}

void	print_result(t_meta *d)
{
	t_ant *a;
	if (!(a = (t_ant *)ft_memalloc(sizeof(t_ant) * (d->ant_total + 1))))
		return ;
	
	assign_path(d, a);

	sender(d, a);
	free(a);
	return ;
}
