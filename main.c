/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:50:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/01 13:54:17 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	ft_printf("test\n");
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_loop(mlx_ptr);
	return (0);
}
