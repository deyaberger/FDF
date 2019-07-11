/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:27:36 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/10 20:06:20 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_buttons(t_struct *t, int y, char *b1, char *b2)
{
	int		j;
	int		size;

	size = WIDTH - ((WIDTH / 10) * 2) + 30;
	j = size;
	while (j != size + 40)
	{
		mlx_pixel_put(t->mlx, t->win, j, y, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, j, y + 40, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, j + 60, y, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, j + 60, y + 40, 0x6F6F6F);
		j++;
	}
	j = y;
	while (j != y + 40)
	{
		mlx_pixel_put(t->mlx, t->win, size, j, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, size + 40, j, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, size + 60, j, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, size + 100, j, 0x6F6F6F);
		j++;
	}
	mlx_string_put(t->mlx, t->win, size + 15, y + 8, 0xBDBDBD, b1);
	mlx_string_put(t->mlx, t->win, size + 75, y + 8, 0xBDBDBD, b2);
}

void	ft_menu(t_struct *t, char **tab, char *pt_img, char **argv)
{
	int		i;
	int		j;

	i = 0;
	(void)argv;
	while (i != WIDTH)
	{
		j = 0;
		while (j != HEIGHT)
		{
			mlx_pixel_put(t->mlx, t->win, i, j, 0x232323);
			j++;
		}
		i++;
	}
	i = 0;
	while (i != WIDTH)
	{
		mlx_pixel_put(t->mlx, t->win, i, (HEIGHT / 9) - 2, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, i, (HEIGHT / 9) - 1, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, i, (HEIGHT / 9), 0x171717);
		i++;
	}
	i = HEIGHT / 9;
	while (i != HEIGHT)
	{
		mlx_pixel_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2), i, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 1, i, 0x6F6F6F);
		i++;
	}
	mlx_string_put(t->mlx, t->win, WIDTH / 18, 2, 0xBDBDBD,
			"Contributors :");
	mlx_string_put(t->mlx, t->win, WIDTH / 13, HEIGHT / 30, 0xBDBDBD, "DBerger");
	mlx_string_put(t->mlx, t->win, WIDTH / 13, (HEIGHT / 30) + 20, 0xBDBDBD, "NCoursol");
	mlx_string_put(t->mlx, t->win, WIDTH / 3, HEIGHT / 50, 0xBDBDBD, "Argv[0] : ");
	mlx_string_put(t->mlx, t->win, WIDTH / 3, (HEIGHT / 30) + 20, 0xBDBDBD, "Map Path : ");
	mlx_string_put(t->mlx, t->win, WIDTH / 2.2, HEIGHT / 50, 0xBDBDBD, argv[0]);
	mlx_string_put(t->mlx, t->win, WIDTH / 2.2,(HEIGHT / 30) + 20, 0xBDBDBD, argv[1]);
	mlx_string_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 30, HEIGHT / 6 - 30, 0xBDBDBD, "Rotate X :");
	mlx_string_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 30, HEIGHT / 6 * 2 - 30, 0xBDBDBD, "Rotate Y :");
	mlx_string_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 30, HEIGHT / 6 * 3 - 30, 0xBDBDBD, "Rotate Z :");
	mlx_string_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 30, HEIGHT / 6 * 4 - 30, 0xBDBDBD, "Deep :");
	mlx_string_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 30, HEIGHT / 6 * 5 - 30, 0xBDBDBD, "Zoom :");
	i = 0;
	while (i != HEIGHT / 9)
	{
		mlx_pixel_put(t->mlx, t->win, WIDTH / 4, i, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, WIDTH / 4 + 1, i, 0x6F6F6F);
		i++;	
	}
	ft_buttons(t, HEIGHT / 6, "<", ">");
	ft_buttons(t, (HEIGHT / 6) * 2, "^", "v");
	ft_buttons(t, (HEIGHT / 6) * 3, "1", "2");
	ft_buttons(t, (HEIGHT / 6) * 4, "/", "*");
	ft_buttons(t, (HEIGHT / 6) * 5, "+", "-");
}
