/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:14:18 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/25 17:58:11 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	usage(void)
{
	ft_putstr("usage: fillit map_file\n");
	ft_putstr("invalid arg number\n");
}

int		fillit(int fd, int **tab, char **map)
{
	int		i;
	int		size;
	int		tetris;

	if (!(tab = create_tab(tab)))
		return (-1);
	if (!((tetris = check_grid(fd, tab)) >= 0))
	{
		free_tab(&tab);
		ft_putendl("error");
		return (-1);
	}
	tab[tetris][0] = 1000;
	size = ft_sqrt(tetris * 4);
	map = create_map(size, map);
	while (solve(&map, tab, size) != 1)
		map = create_map(++size, map);
	i = -1;
	while (++i < size)
		ft_putendl(map[i]);
	free_tab_len(map, size);
	free_tab(&tab);
	tab = NULL;
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**tab;
	char	**map;

	tab = NULL;
	map = NULL;
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
		fillit(fd, tab, map);
	return (0);
}
