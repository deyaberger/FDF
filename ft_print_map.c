/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/05 14:18:47 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_struct *t, char *my_img, char *buf)
{
	int		c;
	int		l;
	int		save;
	int		all;
	int		s;
	int		line;
	int		col;
	char	**array;

	l = 0;
	c = 0;
	all = 0;
	col = 8;
	line = 11;
	s = SPACE;
	t->ax = STARTX;
	t->ay = STARTY;
	t->bx = t->ax;
	t->by = t->ay;
	array = ft_strsplit(buf, ' ');
	while (all < col && col > 0 && line > 0)
	{
		while (l < line - 1)
		{
			save = t->ax;
			while (c < col - 1 && all == 0)
			{
				t->bx += SPACE;
				ft_trace_line(t, my_img, COLOR);
				t->ax = t->bx;
				c++;
			}
			t->ax = save;
			t->bx = t->ax;
			t->by = t->ay + SPACE;
			ft_trace_line(t, my_img, 0xF00FF000);
			t->ay = t->by;
			l++;
			c = 0;
		}
		if (l == line - 1 && all == 0)
		{
			while (c < col -1)
			{
				t->bx += SPACE;
				ft_trace_line(t, my_img, COLOR);
				t->ax = t->bx;
				c++;
			}
		}
		l = 0;
		all++;
		t->ax = STARTX + s;
		t->ay = STARTY;
		s += SPACE;
	}
}
