/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:14:18 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/14 01:32:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void		fillit(int fd)
{
	int		**tab;
	int 	tetris;
	
	if (!(tab = create_tab(tab)))
		return (-1);
	if (!(tetris = (check_grid(fd, tab) >= 0)))
		return (-1);
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
	*/



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

*/