/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/02 14:48:08 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_move(int x, int y, t_struct *t)
{
	t->bx = x;
	t->by = y;
	t->col += 100000;
	tracer_segment(t, t->col);
	return (0);
}

/*int		mouse_press(int button, int x, int y, t_struct *t)
{
	t->bx = x;
	t->by = y;
	if (button == 1)
	{
		t->col += 100000;
		tracer_segment(t, t->col);
	}
	return (0);
}
*/
int		deal_key(int key, t_struct *t)
{

	ft_printf("key : [%d]\n", key);
	if (key == 0)
		ft_printf("merci nico\n");
	if (key == 53)
		exit(0);
	return (0);
}

int		main()
{
	t_struct	t;

	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, 1000, 700, "FDF - Nico");
	t.ax = 1;
	t.ay = 1;
	t.bx = 100;
	t.by = 100;
	t.col = 0x00FF00FF;
	mlx_hook(t.win, 2, 0, deal_key, &t);
	mlx_hook(t.win, 6, 0, mouse_move, &t);
//	mlx_hook(t.win, 4, 0, mouse_press, &t);
	mlx_loop(t.mlx);
	return (0);
}
