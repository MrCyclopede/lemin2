/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:38:27 by rcourtoi          #+#    #+#             */
/*   Updated: 2020/05/18 08:29:05 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		concat(char *dst, char *src)
{
	int i;
	int j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
}

static char		*realloc_and_copy(char *read_buff, int size)
{
	char *new;

	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
	{
		free(read_buff);
		return (NULL);
	}
	ft_bzero(new, size + 1);
	if (read_buff)
		concat(new, read_buff);
	free(read_buff);
	return (new);
}

char			*read_file(void)
{
	char	*read_buff;
	int		size;
	int		finished_reading;

	size = 4;
	finished_reading = 0;
	read_buff = NULL;
	if (!(read_buff = realloc_and_copy(read_buff, size)))
		return (NULL);
	if (size > read(STDIN_FILENO, read_buff, size))
		finished_reading = 1;
	while (!finished_reading)
	{
		size *= 2;
		if (!(read_buff = realloc_and_copy(read_buff, size)))
			return (NULL);
		if (size / 2 >
				read(STDIN_FILENO, &read_buff[ft_strlen(read_buff)], size / 2))
			finished_reading = 1;
	}
	return (read_buff);
}
