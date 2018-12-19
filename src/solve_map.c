/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:55:30 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/18 16:26:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"

int		free_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;	
	}
	free(map);		
}

char	**create_map(int size)
{
	int 	x;
	int 	y;
	char	**map;

	x = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (-1);
	while (x < size)
	{
		y = 0;
		if (!(map[x] = (char *)malloc(sizeof(char) * size)))
		{
			free_map(map);
			return (-1);
		}
		while (map[y] < size)
		{
			map[x][y] == '.';
			y++;
		}
		x++;
	}
	return (map);
}

void	asign_to_map(char **map, int **tab, int x, int y)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 1;
	while (j <= 7)
	{
		k = 0;
		map[x + *(*tab + i)][y + *(*tab + j)] = 'A'; //+num
		while (k < 4)
			k++;
		i = i + 2;
		j = j + 2;
	}
	//num++;
	return (map);
}

void	delete_from_map(char **map, int **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j <= 7)
	{
		map[x + *(*tab + i)][y + *(*tab + j)] = '.';
		i = i + 2;
		j = j + 2;	
	}
	return (map);
}

int		solve_map(int **tab)
{
	int size;

	size = 1;
	create_map(size);



}

char	**ft_place_piece(char **map, int **tab, int x, int y)
{
	int j;
	int k;
//	static int letter;
	int i;

	j = 0;
	k = 1;
//	if (!letter)
//		letter = 0;
	while (k <= 7)
	{
		map[y + *(*tab + k)][x + *(*tab + j)] = 'A'; //+ letter;
		i = 0;
		while (i < 4)
		{
			printf("%s\n", map[i]);
			i++;
		}
		printf("\n");
		k = k + 2;
		j = j + 2;
	}
	//letter++;
	return (map);
}

char	**ft_delete_piece(char **map, int **tab, int x, int y)
{
	int j;
	int k;

	j = 0;
	k = 1;
	while (k <= 7)
	{
		map[y + *(*tab + k)][x + *(*tab + j)] = '.';
		k = k + 2;
		j = j + 2;
	}
	return (map);
}

/*int		ft_solve(char **map, int **tab, int size)
{
	int			x;
	int			y;
	int			j;
	int			k;

	if (*(*tab) == 1000)
		return (1);
	y = 0;
	while (y < size)//iter colone
	{
		x = 0;
		while (x < size)//iter ligne
		{
			k = 1;
			j = 0;
			while (k <= 7 && x + *(*tab + j) < size && y + *(*tab + k) < size &&
			y + *(*tab + k) >= 0 && x + *(*tab + j) >= 0 &&
			map[y + *(*tab + k)][x + *(*tab + j)] == '.')
			{
				if (k == 7)//dispinibilité verifier
				{
					map = ft_place_piece(map, tab, x, y);
					ft_solve(map, tab + 1, size);//on a reussit a placer la piece donc on essaye avec la suivante
					map = ft_delete_piece(map, tab, x, y);// on suprime et on recommence sur la case d'apres
				}
				k = k + 2;
				j = j + 2;
			}
			x++;
		}
		y++;
	}
	return (0);
}*/

int		ft_check_free(char **map, int **tab, int x, int y)
{
	int k;
	int j;
	int i;
	int size;


	size = 0;
	j = 0;
	k = 1;
	while (map[0][size])
		size++;
	size++;
	while (k <= 7 && x + *(*tab + j) < size && y + *(*tab + k) < size &&
	y + *(*tab + k) >= 0 && x + *(*tab + j) >= 0 &&
	map[y + *(*tab + k)][x + *(*tab + j)] == '.')
	{
		if (k == 7)//dispinibilité verifier
			return(1);
		k = k + 2;
		j = j + 2;
	}
	return(0);
}

int		ft_solve(char **map, int **tab, int size)
{
	int			x;
	int			y;

	if (*(*tab) == 1000)
		return (1);
	y = 0;
	while (y < size)//iter colone
	{
		x = 0;
		while (x < size)//iter ligne
		{
			if (ft_check_free(map, tab, x, y) == 1)
			{
				map = ft_place_piece(map, tab, x, y);
				ft_solve(map, tab + 1, size);//on a reussit a placer la piece donc on essaye avec la suivante
				map = ft_delete_piece(map, tab, x, y);// on suprime et on recommence sur la case d'apres
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
char	**ft_place_piece(char **map, int **tab, int num, int x, int y) //tab[x][y]
{
	int i;
	int j;
	int k;

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
