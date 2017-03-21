/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:36:13 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 09:36:16 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	play_up(int i, t_para *p)
{
	while (i > 0)
	{
		p->x = 0;
		p->y = p->size - 1;
		while (p->x < p->size)
		{
			while (p->y > 0)
			{
				if (p->map[p->y][p->x] != 0 && p->map[p->y - 1][p->x] == 0)
				{
					p->map[p->y - 1][p->x] = p->map[p->y][p->x];
					p->map[p->y][p->x] = 0;
					p->flag = 1;
				}
				p->y--;
			}
			p->y = p->size - 1;
			p->x++;
		}
		return (play_up(i - 1, p));
	}
}

static void	add_up(t_para *p)
{
	p->x = 0;
	p->y = 0;
	while (p->x < p->size)
	{
		while (p->y + 1 < p->size)
		{
			if (p->map[p->y][p->x] == p->map[p->y + 1][p->x])
			{
				p->map[p->y][p->x] = p->map[p->y][p->x] +
							p->map[p->y + 1][p->x];
				p->map[p->y + 1][p->x] = 0;
				p->score = p->score + p->map[p->y][p->x];
				p->y += 1;
				p->flag = 1;
			}
			p->y++;
		}
		p->y = 0;
		p->x++;
	}
}

int			print_up(t_para *p)
{
	int	i;

	i = p->size;
	play_up(i, p);
	add_up(p);
	play_up(i, p);
	return (p->flag);
}
