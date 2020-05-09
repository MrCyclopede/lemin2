/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:37:41 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/12 02:56:47 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	get_index(t_meta *d, char *room) // OPTIMIZE WITH MUCH BETTER SHIT
{
	int i;

	i = 0;

	while (i < d->room_total)
	{
		if (ft_strstr(d->room_name[i], room))
			return (i);
		i++;
	}
	return (-1);
}

int	get_ants(t_meta *d)
{
	d->ant_total = ft_atoi(d->parsing);
	if (d->ant_total <= 0)
		return (ERROR);

	while (d->parsing[0] && ft_isdigit(d->parsing[0]))
		d->parsing++;
	if (d->parsing[0] != '\n')
		return (ERROR);
	else
		d->parsing++;
	return (SUCCESS);
}


int		parsing(t_meta *d)
{
	if (!(d->parsing = read_file()))
		return (ERROR);
	//STILL NEED TO CHECK for INFINITE or BuLLShit file /////
	ft_putendl(d->parsing);

	if (!get_ants(d))
		return (ERROR);	

	if (!get_rooms(d))
		return (ERROR);

	if (!get_links(d))
		return (ERROR);	

	
	d->max_path = d->l[d->start].size;
	if (d->room_total >= 10000)
		return (ERROR);
	//	STILL NEED TO SECURE ALL THE WEIRD SHIT LIKE COMMENT AT THE END OF FILE
	//REMEMBER TO TEST FOR nO neWLINE AT ThE END OF ThE FILE 
	return (SUCCESS);
}
