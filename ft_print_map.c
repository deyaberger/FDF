/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/11 15:49:22 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_place_pix(t_struct *t, int z)
{
	int d;
	int save;

	d = t->deep;
	if ((z > 0 && d < 0) || (z < 0 && d < 0))
	{
		d = -d;
		z = -z;
	}
	if (z > 0 && d > 0)
		z += d;
	if (z < 0 && d > 0)
		z -= d;
	save = t->ax;
	t->ax = t->ax * cos((t->anglz * (M_PI / 180))) - t->ay
		* sin((t->anglz * (M_PI / 180)));
	t->ay = save * sin((t->anglz * (M_PI / 180))) + t->ay
		* cos((t->anglz * (M_PI / 180)));
	t->ay = (z >= 0) ? t->ay * cos((t->anglx * (M_PI / 180))) - z
		* cos(t->anglx * (M_PI / 180))
		: t->ay * cos((t->anglx * (M_PI / 180))) + -(z)
		* cos(t->anglx * (M_PI / 180));
	return (z);
}

int		ft_trace_right(t_struct *t, char *my_img, char **tab, int i)
{
	int z;
	int	d;
	int p;

	d = t->deep;
	i++;
	t->ax = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
	t->ay = (((i / t->col) + 1) * t->sp) + t->starty;
	z = ft_atoi(tab[i]);
	z = ft_place_pix(t, z);
	p = t->ay;
	if (z > 0)
		ft_trace_line(t, my_img, t->clrup);
	if (z < 0)
		ft_trace_line(t, my_img, t->clrdown);
	else if (z == 0)
		ft_trace_line(t, my_img, t->clr);
	return (p);
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
	if (z > 0)
		ft_trace_line(t, my_img, t->clrup);
	if (z < 0)
		ft_trace_line(t, my_img, t->clrdown);
	else if (z == 0)
		ft_trace_line(t, my_img, t->clr);
}

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;
	int		save;
	int		sv;
	int		p;

	i = 0;
	while (tab[i])
	{
		t->bx = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
		t->by = (((i / t->col) + 1) * t->sp) + t->starty;
		save = t->bx;
		t->bx = t->bx * cos(t->anglz * (M_PI / 180)) - t->by
			* sin(t->anglz * (M_PI / 180));
		t->by = save * sin((t->anglz * (M_PI / 180))) + t->by
			* cos((t->anglz * (M_PI / 180)));
		t->by = (ft_atoi(tab[i]) != 0) ? p : t->by * cos(t->anglx * (M_PI / 180));
		sv = i;
		if ((i + 1) % (t->col) != 0 && tab[i + 1])
			p = ft_trace_right(t, my_img, tab, i);
		i++;
		if (((i - 1) + t->col) <= (t->col * t->line) - 1)
			ft_trace_down(t, my_img, tab, i);
		i = sv + 1;
	}
}
