/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:42:49 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/20 21:33:23 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		check_contact(char *buff)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (i > 0 && buff[i - 1] == '#')
				count++;
			if (buff[i + 1] == '#')
				count++;
			if (i > 4 && buff[i - 5] == '#')
				count++;
			if (i + 5 < 22 && buff[i + 5] == '#')
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (-1);
	return (1);
}

int		check_buff(char *buff)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (count == 4 && i == 19 && buff[i] == '\n')
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

int		check_grid(int fd, int **tab)
{
	int		ret;
	int		ret_keeper;
	int		tetris;
	char	buff[22];

	tetris = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		ret_keeper = ret;
		if (tetris > 26)
			return (-1);
		else if (check_buff(buff) == -1)
			return (-1);
		else if (check_contact(buff) == -1)
			return (-1);
		else
			create_tetris(tetris, buff, &tab);
		tetris++;
	}
	if (tetris > 26)
		return (-1);
	if (ret_keeper != 20)
		return (-1);
	return (tetris);
}
