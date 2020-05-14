/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:48:16 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/02/24 04:57:37 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_rooms(char *str)
{
	int i;
	int rooms;

	i = 0;
	rooms = 0;
	while (str[i] && str[i] != '-')
	{
		if (str[i] == '\n')
			rooms ++;
		if (str[i] == '#')
		{
			while (str[i] != '\n')
				i++;
		}
		i++;
	}
	return (rooms);
}

static int	get_name(t_meta *d, int n)
{
	int i;
	int space;
	int number;

	i = 0;
	space = 0;
	number = 0;
	d->room_name[n] = d->parsing;
	if (d->parsing[i] == '\n' || d->parsing[i] == 'L')
		return (ERROR);
	while (d->parsing[i] != ' ') // skip the name
		i++;
	if (!i)
		return (ERROR);
	while (d->parsing[i] != '\n') // fill the rest with 0, advance to next line
	{
		if (d->parsing[i] == ' ')
			space ++;
		if (ft_isdigit(d->parsing[i]))
		{
			while (ft_isdigit(d->parsing[i + 1]))
				i++;
			number ++;
		}
		if (((d->parsing[i] != ' ' && !ft_isdigit(d->parsing[i]))))
			return (ERROR);
		d->parsing[i] = '\0';
		i++;
	}
	if (space < 2 || number != 2)
		return (ERROR);
	while (d->parsing[0] != '\n')
		d->parsing++;
	d->parsing++;

	return (SUCCESS);
}

static int	get_comment(t_meta *d, int n)
{
	if (d->parsing[1] == '#')
	{
		if (!ft_strncmp(d->parsing, "##start", 7))
		{
			if (d->start == -1)
				d->start = n;
			else
				return (ERROR);
		}
		else if (!ft_strncmp(d->parsing, "##end", 5))
		{
			if (d->end == -1)
				d->end = n;
			else
				return (ERROR);
		}	
	}
	while (d->parsing[0] != '\n')
		d->parsing++;
	d->parsing++;
	return (SUCCESS);
}

int	get_rooms(t_meta *d)
{
	int i;

	i = 0;
	d->start = -1;
	d->end = -1;
	d->room_total = count_rooms(d->parsing);
	if (!(d->room_name = (char **)ft_memalloc(d->room_total * sizeof (char *))))
		return (ERROR);
	while (i < d->room_total)
	{
		while (d->parsing[0] == '#')
			get_comment(d, i);
		if (!get_name(d, i))
			return (ERROR);
		i++;
	}
	return (SUCCESS);	
}
