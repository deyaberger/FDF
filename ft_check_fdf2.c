/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fdf2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:28:28 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/10 18:11:35 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_nu(char *add)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (add[i] == ' ')
		while (add[i + 1] == ' ')
			i++;
	while (add[i])
	{
		if ((add[i] == ' ' && add[i + 1] != '\n' && add[i + 1] != '\0'
		&& add[i + 1] != ' ') || (i == 0 && add[i] != ' '))
			j++;
		i++;
	}
	return (j);
}

int		ft_read(char *buf, char *add, t_struct *t, int fd)
{
	int		i;
	int		b;

	b = -1;
	while (t->ax != 0)
	{
		i = 0;
		while (!(ft_strchr(add, '\n')) && (t->ax = read(fd, buf, BUF)))
		{
			buf[t->ax] = '\0';
			add = ft_strjoin_f(add, buf, 1);
		}
		b++;
		while (add[i] != '\n' && add[i] != '\0')
			i++;
		add[i] = '\0';
		t->col = (b == 0 ? ft_nu(add) : t->col);
		if (t->ax != 0)
			if (!ft_check_fdf(add, t))
				return (-1);
		add = ft_strcpy(add, &add[i + 1]);
	}
	free(add);
	return (b);
}

int		ft_check_fdf2(char **argv, t_struct *t)
{
	int		fd;
	char	buf[BUF + 1];
	char	*add;
	int		k;

	fd = open(argv[1], O_RDONLY);
	if (read(fd, buf, 0) == -1 || BUF <= 0)
		return (0);
	if (!(add = (char*)malloc(sizeof(char) * (BUF + 1))))
		return (0);
	add[BUF] = '\0';
	t->ax = 1;
	if ((t->line = ft_read(buf, add, t, fd)) == -1)
		return (0);
	close(fd);
	return (1);
}
