/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/09 11:37:37 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;
	int		c;
	int		l;
	int		s;
	int		x;
	int		y;
	int		z;
	int		coor[t->col * t->line][3];

	i = 0;
	l = 0;
	c = 0;
	s = SPACE;

	// segments de departs
	t->ax = STARTX;
	t->bx = t->ax;
	t->ay = 0;
	t->by = 600;
	ft_trace_line(t, my_img, COLOR);
	t->ax = 0;
	t->bx = 800;
	t->ay = STARTY;
	t->by = t->ay;
	ft_trace_line(t, my_img, COLOR);
	// fin segments de depart
	// line = i - (col * (i / col));
	// col = i / col;

	t->ax = STARTX;
	t->ay = STARTY;	
	while (tab[i] && l < t->line)
	{
		x = t->ax + s;
		y = t->ay;
		z = ft_atoi(tab[i]);
		coor[i][0] = z;
		coor[i][1] = (x - y) * cos(30 * (M_PI / 180));
		coor[i][2] = (x + y) * sin(30 * (M_PI / 180));
		printf("coor[%d][z]=%d, coor[%d][x]=%d, coor[%d][y]=%d\n", i, coor[i][0], i, coor[i][1], i, coor[i][2]);
		i++;
		if (c == t->col - 1)
		{
			coor[i][1] = coor[i - t->col][1];
			coor[i][2] = coor[i - t->col][2];
			s = SPACE;
			y += s;
			x= t->ax + s;
			c = 0;
			printf("\n");
			printf("i=%d. i--t->col=%d\n", i, i-t->col);
			l++;
		}
		else
			c++;
		s += 30;
	}
}
