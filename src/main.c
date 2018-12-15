/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:14:18 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/15 23:26:49 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		fillit(int fd)
{
	int		**tab;
	int 	tetris;
	
	tab = NULL;
	if (!(tab = create_tab(tab)))
		return (-1);
	if (!(tetris = (check_grid(fd, tab) >= 0)))
		return (-1);
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

Lire le fichier Done
Checker la grille Done
Stocker les tetriminos 
Resoudre la grille
Afficher le resultat

Checker les free
Checker les noms des erreurs
Checker le nb de pieces (<26?)
Checker si fichier non envoye ou fichier vide

Votre exécutable doit prendre en paramètre un (et un seul) fichier décrivant la liste
des Tetriminos à agencer. 

Si le nombre de paramètres passés à votre exécutable est différent de 1, votre programme
doit afficher son usage et quitter proprement. 

Si vous ignorez ce qu’est un usage, lancez la commande cp sans argument dans votre shell pour vous faire une idée. 
Il n’y aura jamais plus de 26 Tetriminos dans un fichier de description.


//printf("tab[tetris][%d] = %d\ntab[tetris][%d] = %d\n", k - 2, *tab[tetris][k], k - 1, *tab[tetris][k + 1]); 

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
