/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:55:19 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/15 23:05:32 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"

int			**create_tab(int **tab)
{
	int	i;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 26)))
		return (NULL);
	while (i < 26)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 8)))
			return (NULL);
		i++;
	}
	return (tab);
}

void		free_tab(int ***tab)
{
	int	i;
	
	i = 0;
	while (i < 26)
	{
		free(&(*tab[i]));
		i++;	
	}
	free(&(*tab));	
}

void    create_tetris(int tetris, char *buff, int ***tab)
{
	int i;
	int x;
	int y;
	int k;

	i = 0;
	x = 0;
	y = 0;
	k = 2;
	while (buff[i] && buff[i] != '#')
		i++;
	x = i % 5;
	y = i / 5;
	*tab[tetris][0] = 0; 
	*tab[tetris][1] = 0; 
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			*tab[tetris][k] = ((i % 5) - x); 
			*tab[tetris][k + 1] = ((i / 5) - y);
			printf("tab[tetris][%d] = %d\ntab[tetris][%d] = %d\n", k - 2, *tab[tetris][k], k - 1, *tab[tetris][k + 1]); 
			k = k + 2;
		}
		i++;
	}
}

void	print_tetris(int __unused **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 26)
	{
		//j = 0;
		while (j < 8)
		{
			//printf("i = %d\tj = %d\ttab[i][j] = %d\n", i , j, tab[i][j]);
			j++;
		}
		i++;
	}
}


//creer un print tetris
//compter le nb (x) de . avant le \n? si egal + 0, si moins -x si + +x 

/*

int     relative_coord(int i, int j, char *buff)
{
    int nl;
    int pos;
    int i_cpy;
    int j_cpy;

    nl = 0;
    pos = 0;
    i_cpy = i;
    j_cpy = j;
    while (buff[i] && j < i)
    {
        if (buff[i] == '\n')
            nl++;
        i++;
    }
    return (nl);
}

void    create_tetris(int tetris, char *buff, int ***tab)
{
	int i;
    int x;
    int y;
	int k;

	x = 0;
	i = 0;
	k = 0;
	y = 0;
    while (buff[i] && buff[i] != '#')
		i++;
	x = i % 4;
	y = i / 4;
	while (buff[i])
    {
		if (buff[i] == '#')
		{
			*tab[tetris][k] = ((i % 4) - x);
			printf("tab[tetris][%d] = %d\n", k, *tab[tetris][k]);
			k++;
			*tab[tetris][k] = ((i / 4) - y);
			printf("tab[tetris][%d] = %d\n", k, *tab[tetris][k]);
			k++;
			x = i % 4;
			y = i / 4;
		}
        i++;
    }
}

int     relative_coord(int i, int j, char *buff)
{
    int nl;
    int pos;
    int i_cpy;
    int j_cpy;

    nl = 0;
    pos = 0;
    i_cpy = i;
    j_cpy = j;
    while (buff[i] && j < i)
    {
        if (buff[i] == '\n')
            nl++;
        i++;
    }
    return (nl);
}

void    create_tetris(int tetris, char *buff, int ***tab)
{
	int i;
    int j;
    int k;

	i = 0;
	j = 0;
	k = 2;
    while (buff[i] != '#')
		i++;
	i++;
    *tab[tetris][0] = 0;
    *tab[tetris][1] = 0;
    printf("tab[tetris][0] = %d\n", *tab[tetris][0]);
    printf("tab[tetris][1] = %d\n", *tab[tetris][1]);
	j = i;
	while (buff[i])
    {
        if (buff[i] == '#')
        {
			if (relative_coord(i, j, buff) == 0)
			{
				printf("no nl\n");
				*tab[tetris][k] = 1 + i - j;
			}
			else
			{
				printf("nl\n");
            	*tab[tetris][k] = 5 - i - j;
			}
		    printf("tab[tetris][%d] = %d\n", k, *tab[tetris][k]);
            k++;
            *tab[tetris][k] = relative_coord(i, j, buff);
		    printf("tab[tetris][%d] = %d\n", k, *tab[tetris][k]);
            j = i;  
            k++;
        }
        i++;
    }
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
*/
