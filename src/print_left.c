/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 08:54:02 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 12:40:46 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		play_left(int i, t_para *p)
{
	while (i > 0)
	{
		p->x = p->size - 1;
		p->y = 0;
		while (p->y < p->size)
		{
			while (p->x > 0)
			{
				if (p->map[p->y][p->x] != 0 && p->map[p->y][p->x - 1] == 0)
				{
					p->map[p->y][p->x - 1] = p->map[p->y][p->x];
					p->map[p->y][p->x] = 0;
					p->flag = 1;
				}
				p->x--;
			}
			p->x = p->size - 1;
			p->y++;
		}
	play_left(i - 1, p);
	}
	return (p->flag);
}

static void	add_left(t_para *p)
{
	p->x = 0;
	p->y = 0;

	while (p->y < p->size)
	{
		while (p->x + 1 < p->size)
		{
			if (p->map[p->y][p->x] == p->map[p->y][p->x + 1])
			{
				p->map[p->y][p->x] = p->map[p->y][p->x] + p->map[p->y][p->x + 1];
				p->map[p->y][p->x + 1] = 0;
				p->score = p->score + p->map[p->y][p->x];
				p->x += 2;
				printw("%d\n", p->score);
			}
			p->x++;
		}
		p->x = 0;
		p->y++;
	}
}

int		print_left(t_para *p)
{
	int i;

	p->flag = 0;
	i = p->size;
	play_left(i, p);
	add_left(p);
	play_left(i, p);
	return (p->flag);
}
