/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:57:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/10 14:48:20 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "sources/ft_printf/ft_printf.h"
# include "sources/minilibx/mlx.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define COLOR 0xF1ABDD00
# define COLORUP 0xF3E02900
# define STARTX 200
# define STARTY 1
# define SPACE 30
# define ANGLEZ 30
# define ANGLEX 60
# define BUF 2047
# define DEEP 30

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	int		ax;
	int		ay;
	int		bx;
	int		by;
	int		line;
	int		col;
}				t_struct;

int			ft_check_fdf(char *buf, t_struct *t);
int			ft_check_fdf2(char **argv, t_struct *t);
char		**ft_store(char **tab, char **argv, t_struct *t);
void		ft_trace_line(t_struct *t, char *my_img, int col);
void		ft_print_map(t_struct *t, char *my_img, char **tab);

#endif
