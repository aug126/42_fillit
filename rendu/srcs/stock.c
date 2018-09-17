/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:04:23 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/09/09 19:01:58 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		add_piece(t_jeu_fillit *fillit, int code)
{
	t_piece	*piece;
	t_piece *actuel;
	char	ordre;

	piece = (t_piece*)malloc(sizeof(*piece));
	actuel = (t_piece*)malloc(sizeof(*actuel));
	piece->next = NULL;
	piece->type = ft_itoa(code);
	ordre = 'A';
	if (fillit->first == NULL)
	{
		piece->lettre = ordre;
		fillit->first = piece;
	}
	else
	{
		actuel = fillit->first;
		while (actuel->next != NULL && ordre++)
			actuel = actuel->next;
		piece->lettre = ordre + 1;
		actuel->next = piece;
	}
}

int			set_map(t_jeu_fillit *fillit)
{
	int		i;
	int		j;

	i = fillit->map_size * fillit->map_size + fillit->map_size;
	if (!(fillit->map = (char *)malloc(sizeof(char) * (i + 1))))
		return (1);
	j = 1;
	while (i-- > 0)
	{
		if (j % (fillit->map_size + 1) == 0)
			fillit->map[j - 1] = '\n';
		else
			fillit->map[j - 1] = '.';
		j++;
	}
	fillit->map[j] = '\0';
	return (0);
}

int			init_map(t_jeu_fillit *fillit)
{
	int		i;

	i = fillit->nb_pieces * 4;
	fillit->map_size = 1;
	while (fillit->map_size * fillit->map_size < i)
		fillit->map_size += 1;
	set_map(fillit);
	return (0);
}

static void	free_struct(t_piece *piece)
{
	if (piece->next != NULL)
	{
		free_struct(piece->next);
	}
	free(piece);
}

void		free_fillit(t_jeu_fillit *fillit)
{
	free_struct(fillit->first);
	free(fillit->map);
	free(fillit);
}
