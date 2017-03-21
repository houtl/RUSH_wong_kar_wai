/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:01:28 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 19:01:30 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		execute_col(t_para *p)
{
	if (p->map[p->y][p->x] == 2)
	{
		attron(COLOR_PAIR(5));
		printw("%d", p->map[p->y][p->x]);
		attroff(COLOR_PAIR(5));
	}
	else if (p->map[p->y][p->x] == 4)
	{
		attron(COLOR_PAIR(4));
		printw("%d", p->map[p->y][p->x]);
		attroff(COLOR_PAIR(4));
	}
	else if (p->map[p->y][p->x] == 8)
	{
		attron(COLOR_PAIR(7));
		printw("%d", p->map[p->y][p->x]);
		attroff(COLOR_PAIR(7));
	}
	else
		printw("%d", p->map[p->y][p->x]);
}

static void		execute(t_para *p)
{
	int i;

	p->x = -1;
	p->y = 0;
	while (p->y < p->size)
	{
		i = LINES / p->size;
		while (--i)
			printw("\n");
		while (p->x++ < p->size - 1)
		{
			i = COLS / p->size / 2;
			while (--i)
				printw(" ");
			execute_col(p);
			i = COLS / p->size / 2;
			while (--i)
				printw(" ");
		}
		p->x = -1;
		p->y++;
	}
}

void			print_map(t_para *p)
{
	printw("\n\n\n  Score = %d | Score to win = %d\n", p->score, p->win);
	printw(" You may restart anytime by pressing 'R'. \n");
	if (p->max >= p->win)
	{
		attron(COLOR_PAIR(5));
		printw("!!!!! YOU WON !!!!! Do you wish to restart?");
		printw(" :) Press 'Y' for Yes or 'Esc' to come back to the menu.");
		attroff(COLOR_PAIR(5));
	}
	execute(p);
}
