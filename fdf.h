/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:57:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/02 14:47:33 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./sources/GNL/get_next_line.h"
#include "./sources/ft_printf/ft_printf.h"
#include "./sources/minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	void	*img;
	int		ax;
	int		ay;
	int		bx;
	int		by;
	int		col;
}				t_struct;

void	tracer_segment(t_struct *t, int col);

#endif
