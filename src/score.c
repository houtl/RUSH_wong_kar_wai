/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 10:07:53 by thou              #+#    #+#             */
/*   Updated: 2017/03/19 13:05:54 by nozanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	change_score5(t_para *p, int i, char **line)
{
	char	*dst;
	
	while (i >= 9 && i <= 11)
	{
		if (ft_atoi(((*line) + 8)) < p->score)
		{
			dst = strdup("	  ");
			dst = ft_strjoinfree(dst, ft_itoa(i));
			dst = ft_strjoinfree(dst, "		:		");
			dst = ft_strjoinfree(dst, ft_itoa(p->score));
			p->score = ft_atoi(((*line) + 8));
			free(*line);
			*line = dst;
		}
	}
}

static void	change_score4(t_para *p, int i, char **line)
{
	char	*dst;

	while (i >= 3 && i <= 5)
	{
		if (ft_atoi(((*line) + 8)) < p->score)
		{
			dst = strdup("	  ");
			dst = ft_strjoinfree(dst, ft_itoa(i));
			dst = ft_strjoinfree(dst, "		:		");
			dst = ft_strjoinfree(dst, ft_itoa(p->score));
			p->score = ft_atoi(((*line) + 8));
			free(*line);
			*line = dst;
		}
	}
}

static void change_score(t_para *p, int i, char **line)
{
	if (p->size == 4)
		change_score4(p, i, line);
	if (p->size == 5)
		change_score5(p, i, line);
}

void		writescore(t_para *p)
{
	int		i;
	int		fd;
	char	*line;
	char	*dst;

	i = 0;
	dst = NULL;
	if (p->size != 4 || p->size != 5)
		return ;
	fd = open("score.txt", O_RDWR);
	while ((get_next_line(fd, &line)) > 0)
	{
		i++;
		change_score(p, i, &line);
		dst = ft_strjoinfree(dst, line);
		free(line);
	}
	write(fd, dst, ft_strlen(dst));
}
