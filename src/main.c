/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 06:40:51 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/09 02:41:11 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_rooms(t_meta *d)
{
	int i = 0;
	int j = 0;

	j = 0;
	while (j < d->room_total)
	{
			i = 0;
	printf("\033[0;31m[%d%s][%s]\033[0m\n", j , "th room, size:", d->room_name[j]);
			while (i < d->l[j].size)
			{
				
				printf("\033[0;32m[%s]\033[0m", d->room_name[d->l[j].rooms[i]]);
				i++;
			}
			printf("\033[0;31m\033[0m\n");

		j++;
	}
}

void	print_path (t_meta *d, t_path p)
{
	int i;

	i = 0;
	printf("\033[0;34m%s[%d]\033[0m\n","PATH LEN:", p.size);
	while (i < p.size)
	{
		printf("\033[0;35m[%d] = '%d'\033[0m",i, p.rooms[i]);

		printf("\033[0;35m [%s]\033[0m\n",d->room_name[p.rooms[i]]);
		i++;
	}
}
void	print_matrix(t_meta *d, int n)
{
	int *matrix;

	if (n == 1)
	{
		printf("\033[0;32m%s\033[0m\n","EDGE_MATRIX");
		matrix = d->edge_matrix;
	}
	else	if (n == 0)	
	{	
		printf("\033[0;33m%s\033[0m\n","LINK_MATRIX NO LONGER EXIST");

		return ;
	}
	else if (n == 2)
	{	
		printf("\033[0;34m%s\033[0m\n","EDGE_COPY");
		matrix = d->edge_copy;
	}
	int size = d->room_total; // to replace by room_total;
	int i;

	int j = 0;
	int truc = 0;
	printf("[XX]");
	while (truc < size)
	{
		if (truc == d->start)
			printf("\033[0;32m[%2d]\033[0m", truc++);
		else if (truc == d->end)
			printf("\033[0;31m[%2d]\033[0m", truc++);
		else
			printf("[%2d]", truc++);
	}
	printf("\n");
	
	while (j < size)
	{
		
		if (!(i % size))
			printf("\n");
		printf("[%2d]", j);
		i = 0;
		while (i < size)
		{
			if (matrix[i + j * size]  != 0)
				printf("\033[0;31m%3d \033[0m", matrix[i + j * size]);
			else if (i == j)
				printf("\033[0;34m%3d \033[0m", matrix[i + j * size]);
			else
				printf("\033[0;36m%3d \033[0m", matrix[i + j * size]);
			i++;
		}
		j++;
	}
	printf("\n");
}
void	print_group(t_meta *d, t_group g)
{
	int i = 0;
	
	printf("\033[0;33m%s[%d] ===\033[0m\n","Group size", g.size); 
	while (i < g.size)
	{
		print_path(d, g.path_list[i]);
		i++;
	}
	printf("\033[0;33m%s\033[0m\n","==========================");
}


int		main(void)
{
	t_meta d;
	
	ft_bzero(&d, sizeof(t_meta));
	if(!parsing(&d))
	{
		ft_putstr("parsing error\n");
		return (ERROR);
	}
	if (!(solve(&d)))
	{
		ft_putstr("solving error\n");
		return (ERROR);
	}

	print_result(&d);
	return (0);
}
