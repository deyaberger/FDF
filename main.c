/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/03 11:29:45 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	k = read(fd, buf, 2084);
	buf[k] = '\0';
	if (argc != 2 || !ft_check_fdf(buf))
	{
	ft_printf(" ERREUR! %d\n", argc);
		return (0);
	}
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, 2000, 1000, "FDF - Nico");
	mlx_hook(t.win, 2, 0, deal_key, &t);
	mlx_loop(t.mlx);
	return (0);
}
