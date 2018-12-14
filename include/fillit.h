/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:44:30 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/14 01:25:26 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

int     check_contact(char *buff);
int     check_buff(char *buff);
int     check_grid(int fd, int **tab);

int     **create_tab(int **tab);
int     relative_coord(int i, int j, char *buff);
void    create_tetris(int tetris, char *buff, int ***tab);

#endif
