/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:49:51 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:17:33 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** trouve la premiere occurence de c et retourne un pointeur vers cette lui
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)str;
	while (n-- != 0)
		if (*p++ == (unsigned char)c)
			return ((unsigned char *)p - 1);
	return (NULL);
}
