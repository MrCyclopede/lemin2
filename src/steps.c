/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 05:36:39 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/02/21 19:34:51 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	total_len(t_group g)
{
	int i;
	int total;

	total = 0;
	i = 0;
	while (i < g.size)
	{
		total += g.path_list[i].size - 1;
		i++;
	}
	return (total);
}

static int	max_path_len(t_group g)
{
	int i;
	int	max_len;

	max_len = 0;
	i = 0;
	while (i < g.size)
	{
		if (g.path_list[i].size > max_len)
			max_len = g.path_list[i].size - 1; 
		i++;
	}
	return (max_len);
}

int	steps(t_meta *d, t_group g)
{
	int max_len;
	int len;
	int extra;

	max_len = max_path_len(g);
	len = total_len(g);
	extra = d->ant_total - ((max_len * g.size) - len);
	if (extra < 0)
		return (-1); // CA VEUT DIRE CE CHEMIN C DLA MERDE
	return (max_len - 1 + extra / g.size + (extra % g.size != 0));
}
