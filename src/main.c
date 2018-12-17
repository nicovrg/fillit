/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:14:18 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/17 20:06:32 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		fillit(int fd)
{
	int 	tetris;
	int		**tab;
	
	tab = NULL;
	if (!(tab = create_tab(tab)))
		return (-1);
	if (!(tetris = (check_grid(fd, tab) >= 0)))
	{
		free_tab(tab);
		return (-1);
	}

	printf("valid\n");
	return (0);
}

void		usage(void)
{
	ft_putstr("usage: fillit map_file\n");
	ft_putstr("invalid arg number \n");
}

int			main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		usage();
		return (0);
	}
	else if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("couldn't open file\n");
		return (0);
	}
	else
		fillit(fd);
	return (0);
}


/*


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
}

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
*/

/*

Lire le fichier Done
Checker la grille Done
Stocker les tetriminos 
Resoudre la grille
Afficher le resultat

Checker les free (tab[tetris] non free)
Checker les noms des erreurs
Checker le nb de pieces (<26?)
Checker si fichier non envoye ou fichier vide

Votre exécutable doit prendre en paramètre un (et un seul) fichier décrivant la liste
des Tetriminos à agencer. 

Si le nombre de paramètres passés à votre exécutable est différent de 1, votre programme
doit afficher son usage et quitter proprement. 

Si vous ignorez ce qu’est un usage, lancez la commande cp sans argument dans votre shell pour vous faire une idée. 
Il n’y aura jamais plus de 26 Tetriminos dans un fichier de description.


//printf("tab[tetris][%d] = %d\ntab[tetris][%d] = %d\n", k - 2, (*tab)[tetris][k], k - 1, (*tab)[tetris][k + 1]);

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
