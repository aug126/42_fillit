/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:08:10 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/10/01 15:42:18 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int		cheat_norm(t_jeu_fillit *fillit, char *error)
{
	ft_putstr(error);
	free_fillit(fillit);
	return (0);
}

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
		return (cheat_norm(fillit, "usage: fillit input_file\n"));
	if (check_file(fd = open(argv[1], O_RDONLY), fillit) == 1)
		return (cheat_norm(fillit, "error\n"));
	close(fd);
	if (init_map(fillit))
		return (cheat_norm(fillit, "error\n"));
	while (can_fill_map(fillit, fillit->first))
	{
		fillit->map_size += 1;
		set_map(fillit);
	}
	ft_putstr(fillit->map);
	free_fillit(fillit);
	return (0);
}
