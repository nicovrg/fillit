/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:43:13 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/11 14:45:15 by nivergne         ###   ########.fr       */
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
	}
	else
	{
		if (ft_strlen(line) != 0)
			return (-1);
	}
	return (count);
}

int			check_grid(int fd)
{
	int		j;
    int     count;
	char	*line;
	char	*tab;
	
	j = 1;
    count = 0;
	line = NULL;
	tab = NULL;
	while (get_next_line(fd, &line) > 0)        //recupere une ligne avec gnl
	{
        if (check_line(line, j) == -1)          //check si la ligne est valide (# et .)
            return (-1);
		count = count + check_line(line, j);    //additionne les #
        if (j % 5 == 0 && count != 4)           //check que on a bien 4 #
            return (-1);                           
		if (j % 5 != 0)                         //ajoute une ligne si on est pas sur la separation    
			tab[j - 1] = &line;
		j++;
	}
	if (!(ft_strlen(line) > 0))                 //check que la derniere ligne ne soit pas vide
		return (-1);
	if (check_tetri(&tab) != 1)                //check que les tetris soient "valides"
		return (-1);
	return (count);
}

int			check_tetri(char **tab)
{
	int x;
	int y;

	y = 0;
	while (y < 5)                               //on itere sur les colonnes
	{
    	x = 0;
		while (x < 5)                           //on itere sur les lignes
		{
			if ((tab[y][x] == '#') &&
			((y > 0 && tab[y][x] != tab[y - 1][x]) &&
			 (y < 3 && tab[y][x] != tab[y + 1][x]) &&
			 (x < 3 && tab[y][x] != tab[y][x + 1]) &&
			 (x > 0 && tab[y][x] != tab[y][x - 1])))
					return (-1);
			x++;
		}
		y++;
	}
	return (1);
}