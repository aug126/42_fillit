/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:08:10 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/09/09 19:02:21 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, const char *argv[])
{
	t_jeu_fillit	*fillit;
	int				fd;

	fillit = (t_jeu_fillit*)malloc(sizeof(*fillit));
	fillit->first = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file");
		return (0);
	}
	if (check_file(fd = open(argv[1], O_RDONLY), fillit) == 1)
	{
		ft_putstr("error");
		return (0);
	}
	close(fd);
	init_map(fillit);
	while (can_fill_map(fillit, fillit->first))
	{
		fillit->map_size += 1;
		set_map(fillit);
	}
	ft_putstr(fillit->map);
	free_fillit(fillit);
	return (0);
}
