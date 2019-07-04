/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/04 19:03:47 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_struct *t, char *my_img, char *buf)
{
	int		i;
	int		k;
	int		new;
	int		c;
	int		l;
	int		s;

	i = 0;
	k = 0;
	new = 0;
	c = 30;
	l = 0;
	s = 0;
	t->ax = 100;
	t->ay = 100;
	t->bx = t->ax;
	t->by = t->ay;
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9' && buf[i] != '\n')
		{
			k = i;
			s = i;
			i++;
			printf("kfirst=%d, i=%d\n", k, i);
			if ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == 'x')
			{
				while ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == 'x')
				{
					printf("test\n");
					i++;
					l++;
				}
				k = i;
			}
			while (buf[i] && (buf[i] < '0' || buf[i] > '9' || buf[i] == '\n'))
				i++;
			s = i - k + l;
			printf("s=%d, l=%d,  k=%d, i=%d, buf[i]=%c\n", s, l, k, i, buf[i]);
			l = 0;
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				t->bx += (s * 10);
		//		printf("t->ax=%d, t->bx=%d\n t->ay=%d, t->by=%d\n", t->ax, t->bx, t->ay, t->by);
				ft_trace_line(t, my_img, COLOR);
				t->ax = t->bx;
				new += 5000;
			}
			i = k;
		}
		if (buf[i] == '\n')
		{
			printf("\n");
			t->ax = 100;
			t->ay = 100;
			t->bx = t->ax;
			t->by = t->ay + c;
			ft_trace_line(t, my_img, 0xF00FF000);
			t->ay = t->by;
			c += 30;
		}
		i++;
	}
}
