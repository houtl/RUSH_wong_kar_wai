/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:14:33 by thou              #+#    #+#             */
/*   Updated: 2017/03/19 16:19:30 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	print_menu(char **tab, int n, t_para *p)
{
	int		i;

	i = 0;
	clear();
	printw(" WELCOME TO WONG KAR WAI  ");
	attron(COLOR_PAIR(5));
	printw(" SIZE = %d ", p->size);
	attroff(COLOR_PAIR(5));
	printw("		");
	attron(COLOR_PAIR(4));
	printw(" WIN SCORE = %d \n\n", p->win);
	attroff(COLOR_PAIR(4));
	while (tab[i])
	{
		printw("  ");
		if (n == i)
			attron(COLOR_PAIR(3));
		printw(" %s \n", tab[i]);
		if (n == i)
			attroff(COLOR_PAIR(3));
		i++;
	}
}

static char	**init_tab(void)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 7)))
		return (NULL);
	tab[0] = ft_strdup("START GAME");
	tab[1] = ft_strdup("CHANGE WIN VALUE");
	tab[2] = ft_strdup("CHANGE SIZE");
	tab[3] = ft_strdup("RECORD");
	tab[4] = ft_strdup("EXIT");
	tab[5] = 0;
	return (tab);
}

static void	record(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("score.txt", O_RDONLY);
	clear();
	while ((get_next_line(fd, &line)) > 0)
	{
		printw(line);
		printw("\n");
		free(line);
	}
	while ((getch()) != 27)
		;
}

static void	choise(t_para *p, int i)
{
	if (i == 0)
		start(p);
	else if (i == 1 || i == 2)
		change(p, i);
	else if (i == 3)
		record();
}

void		menu(t_para *p)
{
	int		key;
	int		i;
	char	**tab;

	i = 0;
	tab = init_tab();
	print_menu(tab, i, p);
	key = -1;
	while (key != 27)
	{
		if (key == 10)
			print_menu(tab, i, p);
		key = getch();
		if (key == KEY_UP && i > 0)
			print_menu(tab, --i, p);
		else if (key == KEY_DOWN && i < 4)
			print_menu(tab, ++i, p);
		else if (key == 10)
		{
			if (i == 4)
				break ;
			choise(p, i);
		}
	}
	free_tab(tab);
}
