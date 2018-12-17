/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:55:19 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/17 20:06:37 by nivergne         ###   ########.fr       */
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
		free(tab[i]);
		i++;	
	}
	free(tab);	
}

void    	create_tetris(int tetris, char *buff, int ***tab)
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
	(*tab)[tetris][0] = 0; 
	(*tab)[tetris][1] = 0; 
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			(*tab)[tetris][k] = ((i % 5) - x); 
			(*tab)[tetris][k + 1] = ((i / 5) - y);
			//printf("tab[tetris][%d] = %d\ntab[tetris][%d] = %d\n", k - 2, (*tab)[tetris][k], k - 1, (*tab)[tetris][k + 1]);
			k = k + 2;
		}
		i++;
	}
}
