/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_segment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:52 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/01 16:52:15 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	tracer_segment(t_struct *t, int	col)
{
	int		dx;
	int		dy;
	int		i;
	int		x;
	int		y;
	int		cumul;

	dx = t->bx - t->ax;
	dy = t->by - t->ay;
	x = (dx > 0 ? 1 : -1);
	y = (dy > 0 ? 1 : -1);
	dx = (dx < 0 ? -dx : dx);
	dy = (dy < 0 ? -dy : dy);
	mlx_pixel_put(t->mlx, t->win, t->ax, t->ay, col);
	i = 1;
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i <= dx)
		{
			t->ax += x;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				t->ay += y;
			}
			mlx_pixel_put(t->mlx, t->win, t->ax, t->ay, col);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		while (i <= dy)
		{
			t->ay += y;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				t->ax += x;
			}
			mlx_pixel_put(t->mlx, t->win, t->ax, t->ay, col);
			i++;
		}
	}
}
