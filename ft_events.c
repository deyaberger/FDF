/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:46:12 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/14 16:10:05 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     mouse_release(int button, int x, int y, t_struct *t)
{
	int     resx;
	int     resy;
	int     w;
	int     h;

	if (button == 1)
	{
		ft_printf("x : [%d]	y : [%d]\n", t->startx, t->starty);
		h = HEIGHT - (HEIGHT / 9);
		w = WIDTH - ((WIDTH / 10) * 2);
		resx = (t->ax < x) ? t->ax - x : x - t->ax;
		ft_printf("addx : [%d]\n", resx);
		t->startx = (t->ax < x) ? t->startx - resx : t->startx + resx;
		resy = (t->ay > y) ? t->ay - y : y - t->ay;
		ft_printf("addy : [%d]\n", resy);
		t->starty = (t->ay > y) ? t->starty - resy : t->starty + resy;
	//	t->startx = (t->startx + 5 > w) ? w - 5 : t->startx;
	//	t->startx = (t->startx - 5 < 0) ? 5 : t->startx;
	//	t->starty = (t->starty + 5 > h) ? h - 5 : t->starty;
	//	t->starty = (t->starty - 5 < 0) ? 5 : t->starty;
		ft_printf("x : [%d]	y : [%d]\n", t->startx, t->starty);
		ft_key_press(1, t, 0, 1);
	}
	return (0);
}

int     mouse_press(int button, int x, int y, t_struct *t)
{
	int     w;
	int     h;

	h = HEIGHT - (HEIGHT / 9);
	w = WIDTH - ((WIDTH / 10) * 2);
	if (button == 1)
	{
		t->ax = x;
		t->ay = y;
	}
	mlx_hook(t->win, 5, 0, mouse_release, t);
	return (0);
}

int     key_release(int key, t_struct *t)
{
	int     size;

	size = (WIDTH - ((WIDTH / 10) * 2) + 30);
	if (key == 53)
		exit(0);
	else
		ft_key_press(key, t, size, 0);
	return (0);
}

int     key_press(int key, t_struct *t)
{
	int     size;

	size = (WIDTH - ((WIDTH / 10) * 2) + 30);
	if (key == 53)
		exit(0);
	else
		ft_key_press(key, t, size, 1);
	return (0);
}
