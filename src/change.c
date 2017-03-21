/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:52:18 by thou              #+#    #+#             */
/*   Updated: 2017/03/19 20:03:33 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	change_win(t_para *p)
{
	int		win;
	int		key;

	key = -1;
	win = p->win;
	clear();
	printw("	WIN SCORE:   %d  ", win);
	while (key != 10 && key != 27)
	{
		key = getch();
		if (key == 27)
			break ;
		else if (key == KEY_UP && win < 140000)
			win *= 2;
		else if (key == KEY_DOWN && win > 3)
			win /= 2;
		else if (key == 10)
			p->win = win;
		clear();
		printw("	WIN SCORE:   %d  ", win);
	}
}

static void	change_size(t_para *p)
{
	int		size;
	int		key;

	key = -1;
	size = p->size;
	clear();
	printw("	size:	%d	", size);
	while (key != 10 && key != 27)
	{
		key = getch();
		if (key == 27)
			break ;
		else if (key == KEY_UP && size < 10)
			size++;
		else if (key == KEY_DOWN && size > 2)
			size--;
		else if (key == 10)
			p->size = size;
		clear();
		printw("	size:   %d  ", size);
	}
}

void		change(t_para *p, int i)
{
	if (i == 2)
		change_size(p);
	else if (i == 1)
		change_win(p);
}
