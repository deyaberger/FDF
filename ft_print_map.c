/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/09 13:47:32 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;
	int		save;
	int		sv;

	i = 0;
	t->col--;
	while (tab[i])
	{
		t->bx = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
		t->by = (((i / t->col) + 1) * SPACE) + STARTY;
		save = t->bx;
		t->bx = t->bx * cos(30 * (M_PI / 180)) - t->by * sin(30 * (M_PI / 180));
		t->by = save * sin((30 * (M_PI / 180))) + t->by * cos((30 * (M_PI / 180)));
		t->by = t->by * cos((30 * (M_PI / 180)));

		sv = i;
		if (i + 1 <= (t->col * t->line) - 1)
		{
			i++;
			t->ax = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
			t->ay = (((i / t->col) + 1) * SPACE) + STARTY;
			save = t->ax;
			t->ax = t->ax * cos((30 * (M_PI / 180))) - t->ay * sin((30 * (M_PI / 180)));
			t->ay = save * sin((30 * (M_PI / 180))) + t->ay * cos((30 * (M_PI / 180)));
			t->ay = t->ay * cos((30 * (M_PI / 180)));
			ft_trace_line(t, my_img, 0xFF000000);
		}
		if (((i - 1) + t->col + 1) <= (t->col * t->line) - 1)
		{
			i = ((i - 1) + t->col + 1);
			t->ax = (((i - (t->col * (i / t->col))) + 1) * SPACE) + STARTX;
			t->ay = (((i / t->col) + 1) * SPACE) + STARTY;
			save = t->ax;
			t->ax = t->ax * cos((30 * (M_PI / 180))) - t->ay * sin((30 * (M_PI / 180)));
			t->ay = save * sin((30 * (M_PI / 180))) + t->ay * cos((30 * (M_PI / 180)));
			t->ay = t->ay * cos((30 * (M_PI / 180)));
			ft_trace_line(t, my_img, 0x00FF0000);
		}
		i = sv + 1;
	}
}
