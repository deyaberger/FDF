/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:57:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/08 12:27:49 by ncoursol         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 600
# define COLOR 0xF0FF0000
# define STARTX 100
# define STARTY 50
# define SPACE 30
# define BUF 2047

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
void		ft_print_map(t_struct *t, char *my_img, char *buf);

#endif
