/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_segment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:52 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/04 16:45:44 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pix(char *my_img, int x, int y, int color)
{
	int		i;
	int		k;

	i = (((HEIGHT - (HEIGHT - y)) * WIDTH) - (WIDTH - x)) * 4;
	my_img[i + 0] = (((color + COLOR)) & 0xFF000000) >> 24;
	my_img[i + 1] = (((color + COLOR)) & 0x00FF0000) >> 16;
	my_img[i + 2] = (((color + COLOR)) & 0x0000FF00) >> 8;
	my_img[i + 3] = (((color + COLOR)) & 0x000000FF) >> 0;
}

void	ft_trace_line(t_struct *t, char *my_img, int col)
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
	ft_fill_pix(my_img, t->ax, t->ay, col);
//	mlx_pixel_put(t->mlx, t->win, t->ax, t->ay, col);
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
			ft_fill_pix(my_img, t->ax, t->ay, col);
		//	mlx_pixel_put(t->mlx, t->win, t->ax, t->ay, col);
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
			ft_fill_pix(my_img, t->ax, t->ay, col);
		//	mlx_pixel_put(t->mlx, t->win, t->ax, t->ay, col);
			i++;
		}
	}
}
