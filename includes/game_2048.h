/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:39:49 by thou              #+#    #+#             */
/*   Updated: 2017/03/19 17:58:38 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <signal.h>
# include <curses.h>
# include <fcntl.h>

int				g_signal;

enum			e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_para
{
	int		size;
	int		win;
	int		**map;
	int		score;
	int		x;
	int		y;
	int		z;
	int		flag;
	int		max;
}				t_para;

void			free_tab(char **tab);
void			random_two(t_para *p);
void			menu(t_para *p);
void			change(t_para *p, int i);
void			start(t_para *p);
int				play(t_para *p);
void			print_map(t_para *p);
int				print_down(t_para *p);
int				print_up(t_para *p);
int				print_left(t_para *p);
int				print_right(t_para *p);
int				full_map(t_para *p);
void			writescore(t_para *p);
void			free_map(t_para *p);
void			resize_board(t_para *p);

#endif
