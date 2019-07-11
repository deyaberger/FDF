/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:57:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/11 15:46:35 by dberger          ###   ########.fr       */
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

# define WIDTH 1500
# define HEIGHT 1100
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
	int		sp;
	int		anglz;		
	int		anglx;		
	int		angly;		
	int		startx;
	int		starty;
	int		deep;
	int		clr;
	int		clrup;
	int		clrdown;
}				t_struct;

int			ft_check_fdf(char *buf, t_struct *t);
int			ft_check_fdf2(char **argv, t_struct *t);
char		**ft_store(char **tab, char **argv, t_struct *t);
void		ft_trace_line(t_struct *t, char *my_img, int col);
void		ft_print_map(t_struct *t, char *my_img, char **tab);
void        ft_menu(t_struct *t, char **tab, char *pt_img, char **argv);
void		ft_key_press(int key, t_struct *t, int size, int mode);

#endif
