/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strretri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 23:18:31 by nakorchi          #+#    #+#             */
/*   Updated: 2019/06/30 05:33:18 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strretri(char *s, char c, int len)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (!s)
		return (NULL);
	while (s[i] != c && i < len)
		i++;
	if (len <= i)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strncpy(ret, s, i);
	ret[i] = '\0';
	return (ret);
}
