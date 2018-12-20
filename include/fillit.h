/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:44:30 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/19 19:24:33 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

void	usage(void);

int     check_contact(char *buff);
int     check_buff(char *buff);
int     check_grid(int fd, int **tab);

int     **create_tab(int **tab);
void	free_tab(int ***tab);

void    create_tetris(int tetris, char *buff, int ***tab);
int		count_tetris(int tetris);

int		fillit(int fd);

#endif
