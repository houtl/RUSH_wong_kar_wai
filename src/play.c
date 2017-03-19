/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:25:26 by nozanne           #+#    #+#             */
/*   Updated: 2017/03/19 12:53:22 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	ft_move(t_para *p, int key)
{
	if (key == KEY_LEFT)
		return (print_left(p));
	else if (key == KEY_RIGHT)
		return (print_right(p));
	else if (key == KEY_UP)
		return (print_up(p));
	else if (key == KEY_DOWN)
		return (print_down(p));
	return (0);
}

static int checkmap(t_para *p)
{
	t_para *tmp;

	tmp = p;
	if (ft_move(tmp, KEY_LEFT) == 0)
		if (ft_move(tmp, KEY_RIGHT) == 0)
			if (ft_move(tmp, KEY_UP) == 0)
				if (ft_move(tmp, KEY_DOWN) == 0)
					return (0);
	return (1);
}

int			play(t_para *p)
{
	int key;

	key = getch();
	if (key == 27)
		return (0);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
	{
		clear ();
		p->size = 0;
		if(ft_move(p, key) == 1)
		{	
			if (full_map(p) == 0)
				random_two(p);
			print_map(p);
			if (checkmap(p) == 0)
			{
				writescore(p);
				free_map(p);
				return(-1);
			}
		}
	}
	return (1);
}
