/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:36:22 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 22:36:25 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	play_down(int i, t_para *p)
{
	while (i < p->size)
	{
		p->x = 0;
		p->y = 0;
		while (p->x < p->size)
		{
			while (p->y < p->size - 1)
			{
				if (p->map[p->y][p->x] != 0 && p->map[p->y + 1][p->x] == 0)
				{
					p->map[p->y + 1][p->x] = p->map[p->y][p->x];
					p->map[p->y][p->x] = 0;
					p->flag = 1;
				}
				p->y++;
			}
			p->y = 0;
			p->x++;
		}
		return (play_down(i + 1, p));
	}
}

static void	add_down(t_para *p)
{
	p->y = p->size - 1;
	p->x = 0;
	while (p->x < p->size)
	{
		while (p->y > 0)
		{
			if (p->map[p->y][p->x] == p->map[p->y - 1][p->x])
			{
				p->map[p->y][p->x] = p->map[p->y][p->x] +
								p->map[p->y - 1][p->x];
				p->map[p->y - 1][p->x] = 0;
				p->score = p->score + p->map[p->y][p->x];
				p->max = (p->map[p->y][p->x] > p->max) ?
					p->map[p->y][p->x] : p->max;
				p->y -= 1;
				p->flag = 1;
			}
			p->y--;
		}
		p->y = p->size - 1;
		p->x++;
	}
}

int			print_down(t_para *p)
{
	play_down(0, p);
	add_down(p);
	play_down(0, p);
	return (p->flag);
}
