/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:35:21 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:55:12 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** copie n char de src sur dest. si src eset fini avant n, on termine avec \0
*/

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *dst;

	dst = dest;
	while (n && *src)
	{
		*dst++ = *src++;
		n--;
	}
	while (n-- > 0)
		*dst++ = '\0';
	return (dest);
}
