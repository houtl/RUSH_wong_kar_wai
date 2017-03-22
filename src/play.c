/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:25:26 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/21 18:00:36 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_move(t_para *p, int key)
{
	if (key == KEY_DOWN)
		print_down(p);
	if (key == KEY_UP)
		print_up(p);
	if (key == KEY_LEFT)
		print_left(p);
	if (key == KEY_RIGHT)
		print_right(p);
}

static int	check_map(t_para *p)
{
	int x;
	int y;

	x = -1;
	while (++x < (p->size))
	{
		y = -1;
		while (++y < (p->size))
		{
			if (x < (p->size - 1))
				if (p->map[x][y] == p->map[x + 1][y])
					return (1);
			if (y < (p->size - 1))
				if (p->map[x][y] == p->map[x][y + 1])
					return (1);
		}
	}
	return (0);
}

int			play(t_para *p)
{
	int key;
	int i;

	i = p->size;
	key = (getch());
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN
		|| key == 121 || key == 89 || key == 114 || key == 82 || key == 27)
	{
		if (key == 27)
			return (0);
		if (key == 114 || key == 121 || key == 89 || key == 82)
			return (-2);
		clear();
		p->flag = 0;
		ft_move(p, key);
		if (p->flag == 1 && full_map(p) == 0)
			random_two(p);
		if (full_map(p) == 1 && check_map(p) == 0)
			return (-1);
		print_map(p);
	}
	if (g_signal == 1)
		resize_board(p);
	return (1);
}
