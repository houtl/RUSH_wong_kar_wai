/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 08:54:02 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 22:39:06 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	play_left(int i, t_para *p)
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
		return (play_left(i - 1, p));
	}
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
				p->map[p->y][p->x] = p->map[p->y][p->x]
							+ p->map[p->y][p->x + 1];
				p->map[p->y][p->x + 1] = 0;
				p->score = p->score + p->map[p->y][p->x];
				p->max = (p->map[p->y][p->x] > p->max) ?
					p->map[p->y][p->x] : p->max;
				p->x += 1;
				p->flag = 1;
			}
			p->x++;
		}
		p->x = 0;
		p->y++;
	}
}

int			print_left(t_para *p)
{
	int i;

	i = p->size;
	play_left(i, p);
	add_left(p);
	play_left(i, p);
	return (p->flag);
}
