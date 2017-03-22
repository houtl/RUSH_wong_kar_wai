/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 00:39:04 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 23:07:59 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		ft_failed(t_para *p)
{
	int key;
	int y;

	y = 0;
	key = -1;
	printw("\n\n\n\n\n\n       ");
	attron(COLOR_PAIR(1));
	printw("  YOU FAILED!\n\n\n\n WANNA TRY AGAAAAIN?\n\n");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(3));
	printw(" Press 'R' to Restart\n\n\n Press 'Esc' to quit ");
	attroff(COLOR_PAIR(3));
	while (key != 27 && key != 10)
	{
		key = getch();
		if (key == 114 || key == 82 || key == 121 || key == 89)
		{
			start(p);
			return ;
		}
	}
}

static int		map_alloc(t_para *p)
{
	int i;
	int j;

	i = -1;
	if (!(p->map = (int**)malloc(sizeof(int*) * (p->size))))
		return (0);
	while (++i < p->size)
	{
		if (!(p->map[i] = (int*)malloc(sizeof(int) * (p->size))))
			return (0);
		j = -1;
		while (++j < p->size)
			p->map[i][j] = 0;
	}
	return (1);
}

void			start(t_para *p)
{
	int	i;

	if (!(map_alloc(p)))
		return ;
	clear();
	random_two(p);
	random_two(p);
	p->score = 0;
	p->max = 0;
	print_map(p);
	while ((i = play(p)) > 0)
		;
	free_map(p);
	if (i == -1)
		ft_failed(p);
	if (i == -2)
		start(p);
}
