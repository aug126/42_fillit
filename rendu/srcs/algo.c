/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:49:08 by adoat             #+#    #+#             */
/*   Updated: 2018/09/09 18:50:23 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill(t_jeu_fillit *fillit, t_piece *piece, char c)
{
	int		i_code;
	int		x_rel;
	int		y_rel;

	fillit->map[piece->y * (fillit->map_size + 1) + piece->x] = c;
	i_code = 0;
	while (piece->type[i_code] != '\0')
	{
		x_rel = piece->x + (piece->type[i_code] - 53);
		y_rel = piece->y + (piece->type[i_code + 1] - 53);
		fillit->map[y_rel * (fillit->map_size + 1) + x_rel] = c;
		i_code += 2;
	}
	return ;
}

static int	can_fill(t_jeu_fillit *fillit, t_piece *piece, int i_map)
{
	int		x;
	int		y;
	int		i_code;
	int		x_rel;
	int		y_rel;

	x = i_map % (fillit->map_size + 1);
	y = i_map / (fillit->map_size + 1);
	i_code = 0;
	while (piece->type[i_code] != '\0')
	{
		x_rel = x + (piece->type[i_code] - 53);
		y_rel = y + (piece->type[i_code + 1] - 53);
		if (fillit->map[y_rel * (fillit->map_size + 1) + x_rel] != '.')
			return (1);
		i_code += 2;
	}
	piece->x = x;
	piece->y = y;
	return (0);
}

int			can_fill_map(t_jeu_fillit *fillit, t_piece *piece)
{
	int		i_map;

	i_map = 0;
	while (i_map < (fillit->map_size * fillit->map_size + fillit->map_size))
	{
		if (fillit->map[i_map] == '.')
		{
			if (!can_fill(fillit, piece, i_map))
			{
				fill(fillit, piece, piece->lettre);
				if (piece->next != NULL)
				{
					if (can_fill_map(fillit, piece->next) == 1)
						fill(fillit, piece, '.');
					else
						return (0);
				}
				else
					return (0);
			}
		}
		i_map++;
	}
	return (1);
}
