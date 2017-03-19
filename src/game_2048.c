/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:38:40 by thou              #+#    #+#             */
/*   Updated: 2017/03/18 16:54:38 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	initcolor(void)
{
	int		i;

	i = 0;
	init_color(0, 1000, 1000, 1000);
	init_color(1, 850, 850, 850);	
	init_color(2, 680, 384, 664);
	init_color(3, 948, 788, 252);
	init_color(4, 876, 708, 488);
	init_color(5, 980, 496, 380);
	init_color(6, 820, 284, 108);
	init_color(7, 250, 250, 250);
	while (i < 8)
	{
		init_pair(i, 7, i);
		i++;
	}
}

int main()
{
	t_para	p;

	p.score = 0;
	srand(time(NULL));
	p.size = 4;
	p.win = WIN_VALUE;
	initscr();
	raw();
	curs_set(0);
	noecho();
	keypad(stdscr, 1);
	start_color();
	initcolor();
	menu(&p);
	endwin();
	return (0);
}
