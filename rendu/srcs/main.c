/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:08:10 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/09/17 17:01:50 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, const char *argv[])
{
	t_jeu_fillit	*fillit;
	int				fd;

	if (!(fillit = (t_jeu_fillit*)malloc(sizeof(*fillit))))
	{
		ft_putstr("error\n");
		return (0);
	}
	fillit->first = NULL;
	fillit->map = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		free_fillit(fillit);
		return (0);
	}
	if (check_file(fd = open(argv[1], O_RDONLY), fillit) == 1)
	{
		ft_putstr("error\n");
		free_fillit(fillit);
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
