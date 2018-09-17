/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:36:22 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 16:36:23 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*j;
	char	*k;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len--)
	{
		if (*haystack == *needle)
		{
			i = len;
			j = (char *)haystack + 1;
			k = (char *)needle + 1;
			while (i-- && *j && *k && *j == *k)
			{
				j++;
				k++;
			}
			if (!*k)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
