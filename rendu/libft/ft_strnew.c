/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:31:05 by adoat             #+#    #+#             */
/*   Updated: 2018/07/28 15:31:06 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * size + 1);
	if (str)
	{
		str[size + 1] = '\0';
		str[size] = '\0';
		while (size-- > 0)
			str[size] = '\0';
	}
	return (str);
}
