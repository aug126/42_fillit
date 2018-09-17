/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:50:55 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:02:59 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** écris le char c sur len bytes de la string *b
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p_s;

	p_s = b;
	while (len-- != 0)
		*p_s++ = (unsigned char)c;
	return (b);
}
