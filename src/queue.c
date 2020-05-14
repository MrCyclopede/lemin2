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
	ft_bzero(d->queue.q, sizeof(int) * QUEUE_SIZE);
	d->queue.index = 0;
	d->queue.current = 0;
}

int			create_queue(t_meta *d)
{
	ft_bzero(&d->queue, sizeof(t_queue));
	if	(!(d->queue.q = (int *)ft_memalloc(sizeof(int) * QUEUE_SIZE)))
		return (ERROR);
	return (SUCCESS);
}

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
	ft_bzero(d->queue.q, sizeof(int) * QUEUE_SIZE);
	return (-1); // this means we finished the Q is now empty
}

void	add_queue(t_meta *d, int value)
{
	if (d->queue.index < QUEUE_SIZE)
		d->queue.q[d->queue.index] = value;
	else
		return ;
	d->queue.index++;
}
