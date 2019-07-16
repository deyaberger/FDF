/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:57:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/16 09:32:46 by ncoursol         ###   ########.fr       */
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

# define WIDTH 2560
# define HEIGHT 1395
# define BUF 2047
//2560 1395
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
	int		savex;
	int		savey;
	int		savecol;
	int		saveline;
	void	*pt;
	char	*my;
	char	**tab;
}				t_struct;

int			ft_check_fdf(char *buf, t_struct *t);
int			ft_check_fdf2(char **argv, t_struct *t);
char		**ft_store(char **tab, char **argv, t_struct *t);
void		ft_trace_line(t_struct *t, char *my_img, int col);
void		ft_print_map(t_struct *t, char *my_img, char **tab);
void        ft_menu(t_struct *t, char **tab, char *pt_img, char **argv);
void		ft_key_press(int key, t_struct *t, int size, int mode);
void		ft_img(t_struct *t, char **tab, void *pt_img, char *my_img);
void		ft_menu4(t_struct *t);
int			key_release(int key, t_struct *t);
int			key_press(int key, t_struct *t);
void		ft_erase(t_struct *t);
void		ft_move(int key, t_struct *t);

#endif
