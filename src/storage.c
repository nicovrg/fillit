/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:55:19 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/14 00:03:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			**create_tab(int **tab)
{
	int		i;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 26)))
		return (-1);
	while (i < 26)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 8)))
			return (-1);
		i++;
	}
	return (tab);
}

int		**create_tetris(int tetris, char *buff)
{
	int 	i;

	i = 0;
	while (buff[i] != '#')
		i++;

	return ;
}