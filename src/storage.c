/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:55:19 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/14 00:59:16 by nivergne         ###   ########.fr       */
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

int		**create_tetris(int tetris, char *buff, int **tab)
{
	int i;
    int j;
    int k;

	i = 0;
	j = 0;
	k = 2;
    while (buff[i] != '#')
		i++;
    tab[tetris][0] = 0;
    tab[tetris][1] = 0;
	while (buff[i])
    {
        if (buff[i] == '#')
        {
            tab[tetris][k] = ;  
            k++;
        }
        i++;
        j++;
    }
	return ;
}

//compter le nb (x) de . avant le \n? si egal + 0, si moins -x si + +x 