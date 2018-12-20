/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:44:30 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/20 17:40:55 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

void	usage(void);

int		ft_check_free(char ***map, int **tab, int x, int y);
int		check_contact(char *buff);
int		check_buff(char *buff);
int		check_grid(int fd, int **tab);

int		**create_tab(int **tab);
void	free_tab(int ***tab);
char	**ft_map(int size, char **map);
void	ft_free_doubletab(char **tabc, int z);

void	create_tetris(int tetris, char *buff, int ***tab);
int		ft_place_piece(char ***map, int **tab, int x, int y);
int		ft_delete_piece(char ***map, int **tab, int x, int y);

int		ft_solve(char ***map, int **tab, int size);
int		fillit(int fd, int **tab, char **map);

#endif
