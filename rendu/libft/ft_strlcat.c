/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:33:44 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 21:28:56 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** copie n char de src sur dst
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*sour;
	size_t		n;
	size_t		dest_len;

	dest = dst;
	sour = src;
	n = size;
	while (n-- && *dest != '\0')
		dest++;
	dest_len = dest - dst;
	if (++n == 0)
		return (size + ft_strlen(src));
	while (*sour != '\0')
	{
		if (n != 1)
		{
			*dest++ = *sour;
			n--;
		}
		sour++;
	}
	*dest = '\0';
	return (dest_len + (sour - src));
}
