/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/09 18:34:17 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;
	int		z;
	int		save;
	int		sv;

	i = 0;
	while (tab[i])
	{
		t->bx = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
		t->by = (((i / t->col) + 1) * SPACE) + STARTY;
		save = t->bx;
		t->bx = t->bx * cos(ANGLEZ * (M_PI / 180)) - t->by * sin(ANGLEZ * (M_PI / 180));
		t->by = save * sin((ANGLEZ * (M_PI / 180))) + t->by * cos((ANGLEZ * (M_PI / 180)));
		z = ft_atoi(tab[i]);
		if (z > 0)
			z += 30;
		t->by = t->by * cos(ANGLEX * (M_PI / 180)) - z * sin(ANGLEX * (M_PI / 180));
		if (z > 0)
			t->by = t->by - 14;
		sv = i;
		if ((i + 1) % (t->col) != 0)
		{
			i++;
			t->ax = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
			t->ay = (((i / t->col) + 1) * SPACE) + STARTY;
			z = ft_atoi(tab[i]);
			if (z > 0)
				z += 30;
			save = t->ax;
			t->ax = t->ax * cos((ANGLEZ * (M_PI / 180))) - t->ay * sin((ANGLEZ * (M_PI / 180)));
			t->ay = save * sin((ANGLEZ * (M_PI / 180))) + t->ay * cos((ANGLEZ * (M_PI / 180)));
			t->ay = t->ay * cos((ANGLEX * (M_PI / 180))) - z * cos(ANGLEX * (M_PI / 180));
			if (z > 0)
				ft_trace_line(t, my_img, 0x0000FF00);
			else
				ft_trace_line(t, my_img, 0xFF000000);
		}
		else
			i++;
		if (((i - 1) + t->col) <= (t->col * t->line) - 1)
		{
			i = ((i - 1) + t->col);
			t->ax = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
			t->ay = (((i / t->col) + 1) * SPACE) + STARTY;
			z = ft_atoi(tab[i]);
			if (z > 0)
				z += 30;
			save = t->ax;
			t->ax = t->ax * cos((ANGLEZ * (M_PI / 180))) - t->ay * sin((ANGLEZ * (M_PI / 180)));
			t->ay = save * sin((ANGLEZ * (M_PI / 180))) + t->ay * cos((ANGLEZ * (M_PI / 180)));
			t->ay = t->ay * cos((ANGLEX * (M_PI / 180))) - z * cos(ANGLEX * (M_PI / 180));
			if (z > 0)
				ft_trace_line(t, my_img, 0x0000FF00);
			else
				ft_trace_line(t, my_img, 0x00FF0000);
		}
		i = sv + 1;
	}
}
