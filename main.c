/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/09 18:37:59 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(char *my_img, int x, int y, int color)
{
	int		i;

	i = (((HEIGHT - (HEIGHT - y)) * WIDTH) - (WIDTH - x)) * 4;
	my_img[i + 0] = ((color & 0xff000000) >> 24);
	my_img[i + 1] = ((color & 0x00ff0000) >> 16);
	my_img[i + 2] = ((color & 0x0000ff00) >> 8);
	my_img[i + 3] = ((color & 0x000000ff) >> 0);
}

int		deal_key(int key, t_struct *t)
{
	if (key == 53)
		exit(0);
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
	t.win = mlx_new_window(t.mlx, WIDTH, HEIGHT, "FDF - team de choc");
	pt_img = mlx_new_image(t.mlx, WIDTH, HEIGHT);
	my_img = mlx_get_data_addr(pt_img, &(bpp), &(s_l), &(endian));
	ft_print_map(&t, my_img, tab);
	mlx_put_image_to_window(t.mlx, t.win, pt_img, 0, 0);
	mlx_hook(t.win, 2, 0, deal_key, &t);
	mlx_loop(t.mlx);
	return (0);
}
