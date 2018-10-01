/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:04:12 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/10/01 15:33:38 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*init_array_piece(int *array_pieces)
{
	array_pieces[19] = '\0';
	array_pieces[0] = 655666;
	array_pieces[1] = 565758;
	array_pieces[2] = 657585;
	array_pieces[3] = 654656;
	array_pieces[4] = 656676;
	array_pieces[5] = 566667;
	array_pieces[6] = 465647;
	array_pieces[7] = 465666;
	array_pieces[8] = 657566;
	array_pieces[9] = 465657;
	array_pieces[10] = 566657;
	array_pieces[11] = 565767;
	array_pieces[12] = 564757;
	array_pieces[13] = 656667;
	array_pieces[14] = 655657;
	array_pieces[15] = 566676;
	array_pieces[16] = 657556;
	array_pieces[17] = 364656;
	array_pieces[18] = 657576;
	return (array_pieces);
}

static int	verif_type(int code, int *array_pieces)
{
	int		i_array;

	i_array = 0;
	while (array_pieces[i_array] != '\0')
		if (array_pieces[i_array++] == code)
			return (0);
	return (1);
}

static int	check_piece(char *buf, int limit)
{
	int		i;
	int		count_block;

	if (limit != 20 && limit != 21)
		return (1);
	count_block = 0;
	i = -1;
	while (++i < limit)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		{
			if (buf[i] != '\n')
				return (1);
		}
		else if (buf[i] != '.' && buf[i] != '#')
		{
			return (1);
		}
		if (buf[i] == '#')
			count_block++;
	}
	if (count_block != 4)
		return (1);
	return (0);
}

static int	get_shape(char *buf, t_jeu_fillit *fillit)
{
	int		i;
	int		i_first;
	int		code;
	int		array_pieces[20];

	init_array_piece(array_pieces);
	code = 0;
	i = 0;
	while (buf[i++] != '#')
		;
	i_first = i - 1;
	while (i < 20)
	{
		if (buf[i] == '#' && ((code *= 100) || 1))
			code += ((i % 5) - (i_first % 5) + 5) * 10 + (i / 5)
			- (i_first / 5) + 5;
		i++;
	}
	if (verif_type(code, array_pieces) == 0)
	{
		if (add_piece(fillit, code))
			return (1);
		return (0);
	}
	return (1);
}

int			check_file(int fd, t_jeu_fillit *fillit)
{
	char	buf[21];
	int		count_pieces;
	int		limit;
	int		last;

	count_pieces = 0;
	while ((limit = read(fd, buf, 21)) > 0)
	{
		last = limit;
		if (check_piece(buf, limit))
			return (1);
		if (get_shape(buf, fillit))
			return (1);
		count_pieces++;
	}
	if (last != 20 || limit != 0)
		return (1);
	if (count_pieces > 26)
		return (1);
	fillit->nb_pieces = count_pieces;
	return (0);
}
