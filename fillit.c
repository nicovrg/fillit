/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:42:49 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/05 00:12:49 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *line, int j)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	if (j % 5 != 0)
	{
		while (i < 4)
		{
			if (line[i] != '#' && line[i] != '.' && line[4] != '\n')
				return (-1);
			if (line[i] == '#')
				count++;
			i++;
		}
	if (count != 4)
		return (-1);
	}
	else
	{
		if (ft_strlen(line) != 0)
			return (-1);
	}
	return (0);
}

int			check_grid(int fd)
{
	int		j;
	char	*line;
	char	**tab[26];
	
	j = 1;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (check_line(line, j) == -1)
			return (-1);
		j++;
	}
	if (!(ft_strlen(line) > 0))
		return (-1);
	return (1);
}

//rajouter la cretion d'un 2* tab des donner valides dans la fct check grid

int			check_tetri(char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 5)
	{
		while (x < 5)
		{
			if ((tab[y][x] == '#') && 
			((y > 0 && tab[y][x] != tab[y - 1][x]) && 
			 (y < 4 && tab[y][x] != tab[y + 1][x]) &&
			 (x < 4 && tab[y][x] != tab[y][x + 1]) &&
			 (x > 0 && tab[y][x] != tab[y][x - 1])))
					return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
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
	else if (check_grid(fd) == 1)
	{
		printf("This file is valid\n");
		//fillit(fd);
		return (0);
	}
	else
	{
		printf("This file is not valid\n");
		return (0);
	}
	return (0);
}



/*

Lire le fichier
Checker la grille
Resoudre la grille
Afficher le resultat

Votre exécutable doit prendre en paramètre un (et un seul) fichier décrivant la liste
des Tetriminos à agencer. Ce fichier est formaté de façon très précise : chaque description
d’un Tetriminos est sur 4 lignes et deux Tetriminos sont séparés par une ligne vide.
Si le nombre de paramètres passés à votre exécutable est différent de 1, votre programme
doit afficher son usage et quitter proprement. Si vous ignorez ce qu’est un usage,
lancez la commande cp sans argument dans votre shell pour vous faire une idée. Il n’y
aura jamais plus de 26 Tetriminos dans un fichier de description.
La description d’un Tetrimino doit respecter les règles suivantes :
• Exactement 4 lignes de 4 caractères suivis d’un retour à la ligne.
• Un Tetriminos est une pièce de Tetris classique composée de 4 blocs.
• Chaque caractère doit être, soit un ’#’ lorsque la case correspond à l’un des 4
blocs d’un Tetriminos, soit un ’.’ lorsque la case est vide.
• Chaque bloc d’un Tetriminos doit être en contact avec au moins un autre bloc
sur l’un ou l’autre de ses 4 côtés.
Quelques exemples de descriptions de Tetriminos valides :

*/