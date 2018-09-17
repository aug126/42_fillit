/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:25:13 by adoat             #+#    #+#             */
/*   Updated: 2018/08/04 14:42:08 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_start(char const *s)
{
	int		start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	return (start);
}

static int	ft_lenstr(char const *s)
{
	int		len;
	int		n;
	int		st;

	st = ft_start(s);
	len = 0;
	n = 0;
	while (s[st + n] != '\0')
	{
		if (s[st + n] != ' ' && s[st + n] != '\n' && s[st + n] != '\t')
			len = n + 1;
		n++;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		st;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_lenstr(s);
	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	st = ft_start(s);
	i = 0;
	while (s[st + i] != '\0' && i < len)
	{
		str[i] = s[st + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
