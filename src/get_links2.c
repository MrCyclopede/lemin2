/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:57:15 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/22 20:01:55 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		skip_comment(t_meta *d, int i)
{
	int j;

	j = i;
	while (d->parsing[j] && d->parsing[j] != '\n')
		j++;
	j++;
	return (j);
}

int		goto_next_c(t_meta *d, int *i, char c)
{
	while (d->parsing[*i] && d->parsing[*i] != c)
		(*i)++;
	if (!d->parsing[*i])
		return (0);
	return (1);
}
