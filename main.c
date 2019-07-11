/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/11 11:57:59 by ncoursol         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_struct	t;
	void		*pt_img;
	char		*my_img;
	char		**tab;
	int			bpp;
	int			s_l;
	int			endian;
	int			i;
	int			j;

	i = 0;
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
	pt_img = mlx_new_image(t.mlx, WIDTH - ((WIDTH / 10) * 2), HEIGHT - (HEIGHT / 9));
	ft_menu(&t, tab, pt_img, argv);
	my_img = mlx_get_data_addr(pt_img, &(bpp), &(s_l), &(endian));
	ft_print_map(&t, my_img, tab);
	mlx_put_image_to_window(t.mlx, t.win, pt_img, 0, HEIGHT / 9);
	mlx_hook(t.win, 2, 0, key_press, &t);
	mlx_hook(t.win, 3, 0, key_release, &t);
	mlx_loop(t.mlx);
	return (0);
}
