/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:55:30 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/15 23:56:35 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"

char	**ft_map(int size, char **map)
{
	int x;
	int y;

	y = 0;
	if (map != NULL)
		ft_free_doubletab(map, size);
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * size)))
		{
			ft_free_doubletab(map, y);
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

char	**ft_place_piece(char **map, int **tab, int num, int x, int y)
{
	int j;
	int k;
	int i;

	j = 0;
	k = 1;
	while (k <= 7)
	{
		map[y + tab[num][k]][x + tab[num][j]] = 'A' + num;
		i = 0;
		k = k + 2;
		j = j + 2;
	}
	return (map);
}

char	**ft_delete_piece(char **map, int **tab, int n, int x, int y)
{
	int j;
	int k;

	j = 0;
	k = 1;
	while (k <= 7)
	{
		map[y + tab[n][k]][x + tab[n][j]] = '.';
		k = k + 2;
		j = j + 2;
	}
	return (map);
}

char	**ft_solve(char **map, int **tab, int size, int num, int nbr_tetris)
{
	int			x;
	int			y;
	int			j;
	int			k;

	y = 0;
	while (y < size) // iter colone
	{
		x = 0;
		while (x < size)// iter ligne
		{
			k = 1;
			j = 0;
			while (k <= 7 && x + tab[num][j] < size && y + tab[num][k] < size &&
			y + tab[num][k] >= 0 && x + tab[num][j] >= 0 &&
			map[y + tab[num][k]][x + tab[num][j]] == '.')
			{
				if (k == 7) // dispinibilité verifier
				{
					map = ft_place_piece(map, tab, num, x, y);
					if (num == nbr_tetris - 1) // condition de sortie
						return (map);
					ft_solve(map, tab, size, num + 1, nbr_tetris); //on a reussit a placer la piece donc on essaye avec la suivante
					map = ft_delete_piece(map, tab, num, x, y); // on suprime et on recommence sur la case d'apres
				}
				k = k + 2;
				j = j + 2;
			}
			x++;
		}
		y++;
	}
	return (NULL);
}
