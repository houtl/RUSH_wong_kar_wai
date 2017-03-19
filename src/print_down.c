/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:36:22 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 12:41:07 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	play_down(int i, t_para *p)
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
	play_down(i + 1, p);
	}
	return (p->flag);
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
				p->map[p->y][p->x] = p->map[p->y][p->x] + p->map[p->y - 1][p->x];
				p->map[p->y - 1][p->x] = 0;
				p->score = p->score + p->map[p->y][p->x];
				p->y -= 1;
				printw("%d\n", p->score);
			}
			p->y--;
		}
		p->y = p->size - 1;
		p->x++;
	}
}

int		print_down(t_para *p)
{
	int i;

	i = 0;
	p->flag = 0;
	play_down(i, p);
	add_down(p);
	play_down(i, p);
	return (p->flag);
}
