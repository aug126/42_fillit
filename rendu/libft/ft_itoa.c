/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:24:05 by adoat             #+#    #+#             */
/*   Updated: 2018/08/04 18:42:44 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_cptchar(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
	}
	while ((n = (n - (n % 10)) / 10) != 0)
	{
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_cptchar(n);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	len--;
	while (n > 0)
	{
		str[len--] = (n % 10) + 48;
		n = (n - (n % 10)) / 10;
	}
	return (str);
}
