/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:10:17 by adoat             #+#    #+#             */
/*   Updated: 2018/08/04 14:42:22 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static char	*ft_passchar(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static int	ft_cptstr(char *s, char c)
{
	int		cpt;

	cpt = 0;
	s = ft_passchar((char*)s, c);
	if (*s != '\0')
		cpt++;
	while ((s = ft_strchr(s, c)) != NULL)
	{
		s = ft_passchar(s, c);
		if (*s != '\0')
			cpt++;
	}
	return (cpt);
}

static int	ft_lenpiece(char *str, char c)
{
	int		len;

	len = 0;
	while (*str != c && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static void	ft_addword(char **array, char *str, char c, int i)
{
	int		j;

	j = 0;
	while (str[j] != c && str[j] != '\0')
	{
		array[i][j] = str[j];
		j++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**array;
	int		cpt;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	str = (char*)s;
	cpt = ft_cptstr((char*)s, c);
	if (!(array = (char**)malloc(sizeof(*array) * (cpt + 1))))
		return (NULL);
	array[cpt] = (char*)'\0';
	i = 0;
	while (i < cpt)
	{
		str = ft_passchar(str, c);
		len = ft_lenpiece(str, c);
		if (!(array[i] = ft_strnew(len)))
			return (NULL);
		ft_addword(array, str, c, i);
		str += len;
		i++;
	}
	return (array);
}
