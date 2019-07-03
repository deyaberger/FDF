/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:57:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/02 17:26:20 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "includes/GNL/get_next_line.h"
#include "includes/ft_printf/ft_printf.h"
#include "includes/minilibx/mlx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	int		ax;
	int		ay;
	int		bx;
	int		by;
	int		col;
}				t_struct;

int		ft_check_fdf(char *buf);
void	tracer_segment(t_struct *t, int col);

#endif
