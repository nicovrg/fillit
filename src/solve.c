/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:12:24 by jdonati           #+#    #+#             */
/*   Updated: 2018/12/26 01:49:41 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	**create_map(int size, char **map)
{
	int x;
	int y;

	x = 0;
	if (map != NULL)
		free_tab_len(map, size - 1);
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (x < size)
	{
		y = 0;
		if (!(map[x] = (char *)malloc(sizeof(char) * size + 1)))
		{
			free_tab_len(map, x);
			return (NULL);
		}
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	return (map);
}

int		place_piece(char ***map, int **tab, int x, int y)
{
	int j;
	int k;

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

int		delete_piece(char ***map, int **tab, int x, int y)
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

int		check_free(char ***map, int **tab, int x, int y)
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
		if (k == 8)
			return (1);
		k = k + 2;
		j = j + 2;
	}
	return (0);
}

int		solve(char ***map, int **tab, int size)
{
	int			x;
	int			y;
	static int	i = 0;

	y = -1;
	i = (*(*tab) == 1000) ? 1 : i;
	if (i == 1)
		return (1);
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (check_free(map, tab, x, y) == 1)
			{
				place_piece(map, tab, x, y);
				solve(map, tab + 1, size);
				if (i > 0)
					return (1);
				delete_piece(map, tab, x, y);
			}
		}
	}
	return (0);
}
