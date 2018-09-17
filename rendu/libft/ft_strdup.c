/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:54:04 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:24:25 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** alloue de la memoire sur un poiteur pour dubliquer la string *s
*/

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s);
	dup = ft_strnew(i);
	if (!dup)
		return (NULL);
	while (i--)
		dup[i] = s[i];
	return (dup);
}
