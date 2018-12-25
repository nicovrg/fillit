/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:44:30 by nivergne          #+#    #+#             */
/*   Updated: 2018/12/25 17:58:13 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

//main.c
void	usage(void);
int		fillit(int fd, int **tab, char **map);

//parse.c
int		check_contact(char *buff);
int		check_buff(char *buff);
int		check_grid(int fd, int **tab);

//store.c
int		**create_tab(int **tab);
void	free_tab(int ***tab);
void	free_tab_len(char **tab, int len);
void	add_tetris_to_tab(int tetris, char *buff, int ***tab);

//solve.c
char	**create_map(int size, char **map);
int		check_free(char ***map, int **tab, int x, int y);
int		place_piece(char ***map, int **tab, int x, int y);
int		delete_piece(char ***map, int **tab, int x, int y);
int		solve(char ***map, int **tab, int size);

#endif
