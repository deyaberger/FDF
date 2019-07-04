/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/04 14:53:34 by ncoursol         ###   ########.fr       */
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
	int			fd;
	char		buf[2084];
	int			k;
	void		*pt_img;
	char		*my_img;
	int			bpp;
	int			s_l;
	int			endian;

	fd = open(argv[1], O_RDONLY);
	k = read(fd, buf, 2084);
	buf[k] = '\0';
	if (argc != 2 || !ft_check_fdf(buf))
	{
	ft_printf(" ERREUR! %d\n", argc);
		return (0);
	}
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, 800, 600, "FDF - Nico");
	pt_img = mlx_new_image(t.mlx, 800, 600);
	my_img = mlx_get_data_addr(pt_img, &(bpp), &(s_l), &(endian));

	mlx_put_image_to_window(t.mlx, t.win, pt_img, 0, 0);
	mlx_hook(t.win, 2, 0, deal_key, &t);
	mlx_loop(t.mlx);
	return (0);
}
