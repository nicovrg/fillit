/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:42:49 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/12 00:13:25 by nivergne         ###   ########.fr       */
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
			if (buff[i + 5] == '#')
				count++;
			printf("count = %d\n", count);
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
		if (check_contact(buff) == -1)
			return (-1);
		tetris++;
	}
	if (ret_keeper != 19)
		return (-1);
	return (1);
}