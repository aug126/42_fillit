/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:50:43 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:14:34 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** copie n bytes de src sur dst.
 ** la copie est non destructive si les strings se chevauchent.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (s < d)
		while ((int)(--n) >= 0)
			*(d + n) = *(s + n);
	else
		while (++i < n)
			*(d + i) = *(s + i);
	return (dest);
}
