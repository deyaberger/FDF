/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/13 15:16:50 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_release(int key, t_struct *t)
{
	int		size;

	size = (WIDTH - ((WIDTH / 10) * 2) + 30);
	if (key == 53)
		exit(0);
	else
		ft_key_press(key, t, size, 0);
	return (0);
}

int		key_press(int key, t_struct *t)
{
	int		size;

	size = (WIDTH - ((WIDTH / 10) * 2) + 30);
	if (key == 53)
		exit(0);
	else
		ft_key_press(key, t, size, 1);
	return (0);
}

void	ft_macros(t_struct *t, char **tab)
{
	t->sp = 30;
	t->anglz = 0;
	t->anglx = 0;
	t->angly = 0;
	t->startx = 300;
	t->starty = 30;
	t->deep = 1;
	t->clr = 0xF1ABDD00;
	t->clrup = 0xF3E02900;
	t->clrdown = 0x4EF32900;
	t->tab = tab;
}

void    ft_img(t_struct *t, char **tab, void *pt_img, char *my_img)
{
	int         bpp;
	int         s_l;
	int         endian;
	int         i;
	int			h;

	h =	HEIGHT - (HEIGHT / 9);
	i = WIDTH - ((WIDTH / 10) * 2);
	t->sp = (t->sp * t->col > i || t->sp * t->line > h) ? 1 : t->sp;
	t->sp = (t->sp * t->col < -i || t->sp * t->line < -h) ? -1 : t->sp;
	t->anglx = (t->anglx > 360 ) ? 360 : (t->anglx < -360) ? -360 : t->anglx;
	t->angly = (t->angly > 360 ) ? 360 : (t->angly < -360) ? -360 : t->angly;
	t->anglz = (t->anglz > 360 ) ? 360 : (t->anglz < -360) ? -360 : t->anglz;
	t->deep = (t->deep > 100 ) ? 10 : (t->deep < -100) ? -10 : t->deep;
	pt_img = mlx_new_image(t->mlx, i, h);
	my_img = mlx_get_data_addr(pt_img, &(bpp), &(s_l), &(endian));
	t->pt = pt_img;
	t->my = my_img;
	ft_print_map(t, my_img, tab);
	mlx_put_image_to_window(t->mlx, t->win, pt_img, 0, HEIGHT / 9);
}

int     main(int argc, char **argv)
{
	t_struct    t;
	void        *pt_img;
	char        *my_img;
	char        **tab;

	if (argc != 2 || !ft_check_fdf2(argv, &t))
	{
		ft_printf(" fichier d'entree invalide.");
		return (0);
	}
	if (!(tab = ft_store(tab, argv, &t)))
	{
		ft_printf(" malloc error : ft_store.");
		return (0);
	}
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, WIDTH, HEIGHT, "FDF - DeyaNico & Co");
	ft_menu(&t, tab, pt_img, argv);
	ft_macros(&t, tab);
	ft_img(&t, tab, pt_img, my_img);
	mlx_hook(t.win, 2, 0, key_press, &t);
	mlx_hook(t.win, 3, 0, key_release, &t);
	mlx_loop(t.mlx);
	return (0);
}
