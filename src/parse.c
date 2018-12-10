/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:43:13 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/10 14:02:03 by nivergne         ###   ########.fr       */
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
	char	*tab;
	
	j = 1;
	line = NULL;
	tab = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (check_line(line, j) == -1)
			return (-1);
		if (j % 5 != 0)
			tab[j - 1] = &line;
		j++;
	}
	if (!(ft_strlen(line) > 0))
		return (-1);
	if (check_tetri(tab) == -1)
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