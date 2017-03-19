/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 00:39:04 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 12:24:07 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			map_alloc(t_para *p)
{
	int i;
	int j;

	j = -1;
	i = 0;
	if (p->map)
		free_map(p);
	if (!(p->map = (int**)malloc(sizeof(int*) * (p->size))))
		return (0);
	while (i < p->size)
	{
		if (!(p->map[i] = (int*)malloc(sizeof(int) * (p->size))))
			return (0);
		while (p->map[i][j++])
			p->map[i][j] = 0;
		i++;
	}
	return (1);
}

void		random_two(t_para *p)
{
	p->x = (int)rand() % p->size;
	p->y = (int)rand() % p->size;
	p->z = ((int)rand() % 10) ? 2 : 4;
	if (p->map[p->x][p->y] == 0)
	{
		p->map[p->x][p->y] = p->z;
		return ;
	}
	else
		random_two (p);
}

void	print_map(t_para *p)
{
	printw("\n\n\n");
	p->x = -1;
	p->y = 0;
	while (p->y < p->size)
	{
		printw("\n        ");
		while (p->x++ < p->size - 1)
			printw("%d", p->map[p->y][p->x]);
		p->x = -1;
		p->y++;
	}
}

void		start(t_para *p)
{
	if (!(map_alloc(p)))
		return ;
	clear();
	random_two(p);
	random_two(p);
	print_map(p);
	while (play(p) != 0)
		play(p);
}
