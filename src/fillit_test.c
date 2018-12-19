/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdonati <jdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:12:24 by jdonati           #+#    #+#             */
/*   Updated: 2018/12/19 22:01:02 by jdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	**ft_map(int size, char **map)
{
	int x;
	int y;

	y = 0;
//	if (map != NULL)
//		ft_free_doubletab(map, size);
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * size)))
		{
//			ft_free_doubletab(map, y);
			return (NULL);
		}
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

int		ft_place_piece(char ***map, int **tab, int x, int y)
{
	int j;
	int k;
	int i;

	j = 1;
	k = 2;
	while (k <= 8)
	{
		(*map)[y + *(*tab + k)][x + *(*tab + j)] = 'A' + *(*tab);
		k = k + 2;
		j = j + 2;
	}
	return (0);
}

int		ft_delete_piece(char ***map, int **tab, int x, int y)
{
	int j;
	int k;

	j = 1;
	k = 2;
	while (k <= 8)
	{
		(*map)[y + *(*tab + k)][x + *(*tab + j)] = '.';
		k = k + 2;
		j = j + 2;
	}
	return (0);
}

int		ft_check_free(char ***map, int **tab, int x, int y)
{
	int		k;
	int		j;
	int		size;

	size = 0;
	j = 1;
	k = 2;
	while ((*map)[0][size])
		size++;
	while (k <= 8 && x + *(*tab + j) < size && y + *(*tab + k) < size &&
	y + *(*tab + k) >= 0 && x + *(*tab + j) >= 0 &&
	(*map)[y + *(*tab + k)][x + *(*tab + j)] == '.')
	{
		if (k == 8)//dispinibilité verifier
			return(1);
		k = k + 2;
		j = j + 2;
	}
	return(0);
}

int		ft_solve(char ***map, int **tab, int size)
{
	int			x;
	int			y;
	static	int	i;

	y = 0;
	if (*(*tab) == 1000)
	{
		i = 1;
		return (1);
	}
	while (y < size)//iter colone
	{
		x = 0;
		while (x < size)//iter ligne
		{
			if (ft_check_free(map, tab, x, y) == 1)
			{
				ft_place_piece(map, tab, x, y);
				ft_solve(map, tab + 1, size);//on a reussit a placer la piece donc on essaye avec la suivante
				if (i > 0)
					return (0);
				ft_delete_piece(map, tab, x, y);// on suprime et on recommence sur la case d'apres
			}
			x++;
		}
		y++;
	}
	return (0);
}