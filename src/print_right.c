/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:36:02 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 09:36:05 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	play_right(int i, t_para *p)
{
	while (i < p->size)
	{
		p->x = 0;
		p->y = 0;
		while (p->y < p->size)
		{
			while (p->x < p->size - 1)
			{
				if (p->map[p->y][p->x] != 0 && p->map[p->y][p->x + 1] == 0)
				{
					p->map[p->y][p->x + 1] = p->map[p->y][p->x];
					p->map[p->y][p->x] = 0;
					p->flag = 1;
				}
				p->x++;
			}
			p->x = 0;
			p->y++;
		}
		return (play_right(i + 1, p));
	}
}

static void	add_right(t_para *p)
{
	p->x = p->size - 1;
	p->y = 0;
	while (p->y < p->size)
	{
		while (p->map[p->y][p->x - 1])
		{
			if (p->map[p->y][p->x] == p->map[p->y][p->x - 1])
			{
				p->map[p->y][p->x] = p->map[p->y][p->x] +
				p->map[p->y][p->x - 1];
				p->map[p->y][p->x - 1] = 0;
				p->score = p->score + p->map[p->y][p->x];
				p->x -= 1;
				p->flag = 1;
			}
			p->x--;
		}
		p->x = p->size - 1;
		p->y++;
	}
}

int			print_right(t_para *p)
{
	play_right(0, p);
	add_right(p);
	play_right(0, p);
	return (p->flag);
}
