/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:53:45 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 20:45:51 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** copie str sur dest avec un \0 a la fin (ne peuvent pas se supperposer)
*/

char	*ft_strcpy(char *dest, const char *src)
{
	char *dst;

	dst = dest;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dest);
}
