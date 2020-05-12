/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:12:49 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/02/10 00:56:49 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


void		reset_queue(t_meta *d)
{
	ft_bzero(d->queue.q, sizeof(int) * 20000);
	d->queue.index = 0;
	d->queue.current = 0;
}

int			create_queue(t_meta *d)
{
	ft_bzero(&d->queue, sizeof(t_queue));
	if	(!(d->queue.q = (int *)ft_memalloc(sizeof(int) * 20000)))
		return (ERROR);
	return (SUCCESS);
}
//PENSER A FREE CE TRUC HE OUAIS
int			queue_next(t_meta *d)
{
	int ret;

	ret = -1;
	if (d->queue.current < d->queue.index)
	{
		ret = d->queue.q[d->queue.current];
		d->queue.current++;
		return (ret);
	}
	ft_bzero(d->queue.q, sizeof(int) * 20000);
	return (-1); // this means we finished the Q is now empty
}

void	add_queue(t_meta *d, int value)
{
	if (d->queue.index < 20000)
		d->queue.q[d->queue.index] = value;
	else
		return ;
	d->queue.index++;
}
