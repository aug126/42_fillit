/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:50:24 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:02:22 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** copie n bytes de src sur dest
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p_d;
	const char	*p_s;

	p_d = (char *)dest;
	p_s = (const char *)src;
	while (n-- != 0)
		*p_d++ = *p_s++;
	return (dest);
}
