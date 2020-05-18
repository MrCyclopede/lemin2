/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 06:40:51 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/18 07:39:34 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_meta d;

	ft_bzero(&d, sizeof(t_meta));
	if (!parsing(&d))
	{
		free_meta(&d);
		ft_putstr("ERROR\n");
		return (ERROR);
	}
	if (!(solve(&d)))
	{
		free_meta(&d);
		ft_putstr("ERROR\n");
		return (ERROR);
	}
	ft_putendl(d.parsing_cpy);
	print_result(&d);
	free_meta(&d);
	return (0);
}
