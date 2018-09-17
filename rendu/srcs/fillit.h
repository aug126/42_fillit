/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:05:09 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/09/17 15:23:23 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_piece
{
	char			lettre;
	int				x;
	int				y;
	char			*type;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_jeu_fillit
{
	int				map_size;
	int				nb_pieces;
	char			*map;
	t_piece			*first;
}					t_jeu_fillit;

int					check_file(int fd, t_jeu_fillit *fillit);
int					add_piece(t_jeu_fillit *fillit, int code);
int					init_map(t_jeu_fillit *fillit);
int					can_fill_map(t_jeu_fillit *fillit, t_piece *piece);
int					set_map(t_jeu_fillit *fillit);
void				free_fillit(t_jeu_fillit *fillit);

#endif
