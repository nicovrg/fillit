/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:55:19 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/20 19:37:24 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int			**create_tab(int **tab)
{
	int	i;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 27)))
		return (NULL);
	while (i < 27)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 9)))
			return (NULL);
		i++;
	}
	return (tab);
}

void		free_tab(int ***tab)
{
	int	i;

	i = 0;
	while (i < 27)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void		ft_free_doubletab(char **tabc, int z)
{
	int i;

	i = 0;
	while (i < z)
	{
		if (tabc[i])
			free(tabc[i]);
		tabc[i] = NULL;
		i++;
	}
	free(tabc);
	tabc = NULL;
}

void		create_tetris(int tetris, char *buff, int ***tab)
{
	int i;
	int x;
	int y;
	int k;

	i = 0;
	k = 1;
	while (buff[i] && buff[i] != '#')
		i++;
	x = i % 5;
	y = i / 5;
	(*tab)[tetris][0] = tetris;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			(*tab)[tetris][k] = ((i % 5) - x);
			(*tab)[tetris][k + 1] = ((i / 5) - y);
			k = k + 2;
		}
		i++;
	}
}
