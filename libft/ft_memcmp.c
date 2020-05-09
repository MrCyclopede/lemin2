/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:01:55 by rcourtoi          #+#    #+#             */
/*   Updated: 2018/11/11 04:37:30 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (((const unsigned char *)s1)[x] != ((const unsigned char *)s2)[x])
			return (((const unsigned char *)s1)[x] -
					((const unsigned char *)s2)[x]);
			x++;
	}
	return (0);
}
