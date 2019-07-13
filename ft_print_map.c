/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/13 18:35:48 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_place_pix(t_struct *t, int z)
{
	int d;

	d = t->deep;
	if (z != 0)
		z = z * d;
	t->ax = t->ax * cos((t->anglz) * (M_PI / 180)) - t->ay
			* sin(((t->anglz) * (M_PI / 180)));
	t->ay = t->ax * sin((t->anglz) * (M_PI / 180)) + t->ay
			* cos(((t->anglz) * (M_PI / 180)));
	t->ay = (z >= 0) ? t->ay * cos((t->anglx) * (M_PI / 180))
			- z * sin(t->anglx * (M_PI / 180))
			: t->ay * cos((t->anglx) * (M_PI / 180))
			+ (-z) * sin((t->anglx) * (M_PI / 180));
	t->ax = (z >= 0) ? t->ax * cos((t->angly) * (M_PI / 180))
			- z * sin((t->angly) * (M_PI / 180))
			: t->ax * cos((t->angly * (M_PI / 180)))
			+ (-z) * sin((t->angly) * (M_PI / 180));
	return (z);
}

void	ft_trace_right(t_struct *t, char *my_img, char **tab, int i)
{
	int 	z;
	int		d;
	int 	p;
	char	*color;

	d = t->deep;
	i++;
	t->ax = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
	t->ay = (((i / t->col) + 1) * t->sp) + t->starty;
	z = ft_atoi(tab[i]);
	z = ft_place_pix(t, z);
	t->savey = t->ay;
	t->savex = t->ax;
	if (z > 0 && i > 0)
		ft_trace_line(t, my_img, t->clrup);
	if (z < 0 && i > 0)
		ft_trace_line(t, my_img, t->clrdown);
	else if (z == 0 && i > 0)
		ft_trace_line(t, my_img, t->clr);
}

void	ft_trace_down(t_struct *t, char *my_img, char **tab, int i)
{
	int	z;
	int d;
	int save;

	d = t->deep;
	i = ((i - 1) + t->col);
	t->ax = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
	t->ay = (((i / t->col) + 1) * t->sp) + t->starty;
	z = ft_atoi(tab[i]);
	z = ft_place_pix(t, z);
	if (i % t->col == 0)
	{
		t->savecol = t->ax;
		t->saveline = t->ay;
	}
	if (z > 0 && i > 0)
		ft_trace_line(t, my_img, t->clrup);
	if (z < 0 && i > 0)
		ft_trace_line(t, my_img, t->clrdown);
	else if (z == 0 && i > 0)
		ft_trace_line(t, my_img, t->clr);
}

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;
	int		sv;

	i = 0;
	ft_trace_right(t, my_img, tab, -1);
	while (tab[i])
	{
		t->bx = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
		t->by = (((i / t->col) + 1) * t->sp) + t->starty;
		t->bx = t->bx * cos((t->anglz) * (M_PI / 180)) - t->by
				* sin(t->anglz * (M_PI / 180));
		t->by = t->bx * sin((t->anglz) * (M_PI / 180)) + t->by
				* cos((t->anglz) * (M_PI / 180));
		t->by = (ft_atoi(tab[i]) != 0 && (i % t->col) != 0) ? t->savey
				: t->by * cos((t->anglx) * (M_PI / 180));
		t->bx = (ft_atoi(tab[i]) != 0 && (i % t->col) != 0) ? t->savex
				: t->bx * cos(t->angly * (M_PI / 180));
		if (ft_atoi(tab[i]) && i > 0 && (i % t->col) == 0)
		{
			t->bx = t->savecol;
			t->by = t->saveline;
		}
		sv = i;
		if ((i + 1) % (t->col) != 0 && tab[i + 1])
			ft_trace_right(t, my_img, tab, i);
		i++;
		if (((i - 1) + t->col) <= (t->col * t->line) - 1)
			ft_trace_down(t, my_img, tab, i);
		i = sv + 1;
	}
}
