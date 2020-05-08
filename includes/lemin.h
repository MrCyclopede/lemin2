/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 06:37:13 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/03/12 03:11:47 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h> ///////REMOVE 

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

# define SUCCESS 1
# define ERROR 0
# define INT_MAX __INT_MAX__




typedef struct	s_queue
{
	int index;
	int current;
	int *q;
}			t_queue;

typedef struct	s_path
{
	int size;
	int	stop;
	int *rooms;
}				t_path;

typedef struct	s_group
{
	int size;
	int steps;
	t_path *path_list;
}				t_group;

typedef struct 	s_ant
{
	t_path *path;
	int		room_index;
	int		send_round;
}				t_ant;

typedef struct 	s_links
{
	int size;
	int index;
	int	*rooms;
}				t_links;

typedef struct	s_meta
{
	char *parsing;
	char **room_name;

	int start; 		// set to -1 
	int end; 		// set to -1
	int max_path;
	int ant_total;
	int room_total;

	t_links *l;





	t_group	best;

	int		*edge_matrix;
	int		*edge_copy;
	int		*depth; /// TO USE ahahaHAAhahaAHahaaAhaaHAAHAHAHAAHAHAAH
	int		*visited;
	int		*prev;
	t_queue queue;
	
}				t_meta;

void		print_rooms(t_meta *d);
void		print_group(t_meta *d, t_group g);
void		print_matrix(t_meta *d, int n);
void		print_path (t_meta *d, t_path p);
//####### PARSING####//////
int	get_index(t_meta *d, char *room);
int			parsing(t_meta *d);		
int			get_rooms(t_meta *d);
int			get_links(t_meta *d);
char		*read_file(void);
//#### SOLVING #######
int	steps(t_meta *d, t_group g);
t_path		pathfinder_bfs(t_meta *d);
t_path		first_pass_bfs(t_meta *d);
t_group		find_group(t_meta *d);
int			solve(t_meta *d);
//########ANTS////////////
void	print_result(t_meta *d);
//######LINK#########
int			path_len(t_meta *d);
void		path_remove(t_meta *d, t_path p, int *matrix);
int			path_update(t_meta *d, t_path p);
int			get_link(t_meta *d, int *matrix, int from, int to);
//#### QUEUE ##################################//
int			create_queue(t_meta *d);			//
int			queue_next(t_meta *d);			//
void		add_queue(t_meta *d, int value);
void		reset_queue(t_meta *d);

//#### LIBFT ##################################//



#endif 
