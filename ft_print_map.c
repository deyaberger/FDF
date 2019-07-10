/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/10 15:35:26 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_trace_right(t_struct *t, char *my_img, char **tab, int i, int save)
{
	int z;
	int	d;

	d = DEEP;
	i++;
	t->ax = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
	t->ay = (((i / t->col) + 1) * SPACE) + STARTY;
	z = ft_atoi(tab[i]);
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
	t->ax = t->ax * cos((ANGLEZ * (M_PI / 180))) - t->ay * sin((ANGLEZ * (M_PI / 180)));
	t->ay = save * sin((ANGLEZ * (M_PI / 180))) + t->ay * cos((ANGLEZ * (M_PI / 180)));
	t->ay = (z >= 0) ? t->ay * cos((ANGLEX * (M_PI / 180))) - z * cos(ANGLEX * (M_PI / 180))
		: t->ay * cos((ANGLEX * (M_PI / 180))) + -(z) * cos(ANGLEX * (M_PI / 180));
	save = t->ay;
	z != 0 ? ft_trace_line(t, my_img, COLORUP) : ft_trace_line(t, my_img, COLOR);
	return (save);
}

void	ft_trace_down(t_struct *t, char *my_img, char **tab, int i, int save)
{
	int	z;
	int d;

	d = DEEP;
	i = ((i - 1) + t->col);
	t->ax = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
	t->ay = (((i / t->col) + 1) * SPACE) + STARTY;
	z = ft_atoi(tab[i]);
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
	t->ax = t->ax * cos((ANGLEZ * (M_PI / 180))) - t->ay * sin((ANGLEZ * (M_PI / 180)));
	t->ay = save * sin((ANGLEZ * (M_PI / 180))) + t->ay * cos((ANGLEZ * (M_PI / 180)));
	t->ay = (z >= 0) ? t->ay * cos((ANGLEX * (M_PI / 180))) - z * cos(ANGLEX * (M_PI / 180))
		: t->ay * cos((ANGLEX * (M_PI / 180))) + (-z) * cos(ANGLEX * (M_PI / 180));
	z != 0 ? ft_trace_line(t, my_img, COLORUP) : ft_trace_line(t, my_img, COLOR);
}

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;
	int		z;
	int		save;
	int		sv;
	int		p;

	i = 0;
	while (tab[i])
	{
		t->bx = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
		t->by = (((i / t->col) + 1) * SPACE) + STARTY;
		save = t->bx;
		t->bx = t->bx * cos(ANGLEZ * (M_PI / 180)) - t->by * sin(ANGLEZ * (M_PI / 180));
		t->by = save * sin((ANGLEZ * (M_PI / 180))) + t->by * cos((ANGLEZ * (M_PI / 180)));
		z = ft_atoi(tab[i]);
		t->by = (z != 0) ? p :  t->by * cos(ANGLEX * (M_PI / 180));
		sv = i;
		if ((i + 1) % (t->col) != 0)
			p = ft_trace_right(t, my_img, tab, i, save);
		i++;
		if (((i - 1) + t->col) <= (t->col * t->line) - 1)
			ft_trace_down(t, my_img, tab, i, save);
		i = sv + 1;
	}
}
