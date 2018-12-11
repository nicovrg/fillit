/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:42:49 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/11 21:27:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		check_buff(char *buff)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (count == 4 && i == 20 && buff[i] == '\n')
			return (1);
		if ((i + 1) % 5 == 0 && buff[i] != '\n')
			return (-1);
		else if ((i + 1) % 5 != 0 && (buff[i] != '#' && buff[i] != '.')) 
			return (-1);
		if (buff[i] == '#')
			count++;
		i++;
	}
	return (-1);
}

int			check_grid(int fd)
{
	int		ret;
	int		ret_keeper;
	int		tetris;
	char	*buff;

	ret = 0;
	ret_keeper = 0;
	tetris = 0;
	buff = ft_strnew(21);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		ret_keeper = ret;
		if (check_buff(buff) == -1)
			return (-1);
		tetris++;
	}
	if (ret_keeper != 19)
		return (-1);
	return (1);
}


/*
int		check_line(char *line, int j)
{
	int i;

	i = 0;
	if (j % 5 != 0)
	{
		while (i < 4)
		{
			if (line[i] != '#' && line[i] != '.' && line[4] != '\n')
				return (-1);
			i++;
		}
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

int			check_tetri()
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 5)
	{
		while ( y < 5)
		{
			if ((tab[x][y] == '#') && 
			((x > 0 && (tab[x][y] != tab[x - 1][y])) || 
			 (x < 4 && (tab[x][y] != tab[x + 1][y])) ||
			 (y < 4 && tab[x][y] != tab[x][y + 1]) ||
			  (y > 0 && tab[x][y] != tab[x][y - 1])))
					return (-1);
			y++;
		}
		y = 0;
		x++;
		}
	}
}
*/


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