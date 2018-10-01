/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:04:23 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/10/01 15:09:30 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			add_piece(t_jeu_fillit *fillit, int code)
{
	t_piece	*piece;
	t_piece *actuel;
	char	ordre;

	piece = (t_piece*)malloc(sizeof(*piece));
	actuel = (t_piece*)malloc(sizeof(*actuel));
	if (piece == NULL || actuel == NULL)
		return (1);
	piece->next = NULL;
	if ((piece->type = ft_itoa(code)) == NULL)
		return (1);
	ordre = 'A';
	if ((fillit->first == NULL) && (piece->lettre = ordre))
		(fillit->first = piece);
	else
	{
		actuel = fillit->first;
		while (actuel->next != NULL && ordre++)
			actuel = actuel->next;
		piece->lettre = ordre + 1;
		actuel->next = piece;
	}
	return (0);
}

int			set_map(t_jeu_fillit *fillit)
{
	int		i;
	int		j;

	i = fillit->map_size * fillit->map_size + fillit->map_size;
	free(fillit->map);
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
	if (set_map(fillit))
		return (1);
	return (0);
}

static void	free_struct(t_piece *piece)
{
	if (piece->next != NULL)
		free_struct(piece->next);
	free(piece->type);
	free(piece);
}

void		free_fillit(t_jeu_fillit *fillit)
{
	if (fillit->first != NULL)
		free_struct(fillit->first);
	free(fillit->map);
	free(fillit);
}
