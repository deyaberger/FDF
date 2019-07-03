/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/02 18:04:07 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_struct	ft_conv_map(t_struct *t, char *argv)
{
	int		fd;
	int		k;
	char 	buf[2048];
	int		c;
	int		l;
	int		i;

	c = 0;
	l = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	k = read(fd, buf, 2048);
	buf[k] = '\0';
	ft_printf("%s\n", buf);
	while (buf[i] && buf[i] != '\n') 
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			tracer_segment(t, t->col);
			t->ax = t->ax + 50;
			t->bx = t->bx + 50;
			c++;
		}
		i++;
	}
	ft_printf("i=%d, c=%d\n", i, c);
	return (*t);
}
