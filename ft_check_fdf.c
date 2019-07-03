/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:12:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/03 11:29:02 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_num_fdf2(char *buf, int *i, int *k, int j)
{
	if (buf[*i] == ' ' && buf[*i + 1] >= '0' && buf[*i + 1] <= '9'
	&& (buf[*i + 2] < '0' || buf[*i + 2] > '9'))
		return (0);
	if (buf[*i] == ' ')
		*k -= 1;
	if (buf[*i] == '\n' || buf[*i] == '\0')
	{
		if (*k != 0)
			return (0);
		*k = j;
	}
	if (buf[*i] != '\0')
	{
		if (buf[*i + 1] != '-' && (buf[0] < '0' || buf[0] > '9'))
			return (0);
		if (buf[*i + 1] == ' ')
			*i += 2;
		else
			*i += 1;
	}
	return (1);
}

int		ft_num_fdf(char *buf, int *i, int *k, int j)
{
	char	vir;

	vir = 'n';
	while (buf[*i] != ' ' && buf[*i] != '\n' && buf[*i] != '\0')
	{
		if (!((buf[*i] >= '0' && buf[*i] <= '9') || buf[*i] == ','
		|| buf[*i] == 'x' || buf[*i] == '-' || buf[*i] == 'X'
		|| (buf[*i] >= 'A' && buf[*i] <= 'F')
		|| (buf[*i] >= 'a' && buf[*i] <= 'f')))
			return (0);
		if ((((buf[*i] >= 'A' && buf[*i] <= 'F')
		|| buf[*i] == 'X') && vir == 'n')
		|| (((buf[*i] >= 'a' && buf[*i] <= 'f')
		|| buf[*i] == 'x') && vir == 'n'))
			return (0);
		if (buf[*i] == ',')
			vir = 'y';
		if ((buf[*i] == ',' && (buf[*i + 1] != '0'
		|| (buf[*i + 2] != 'x' && buf[*i + 2] != 'X')))
		|| (buf[*i] == ',' && (buf[*i - 1] < '0' || buf[*i - 1] > '9')))
			return (0);
		*i += 1;
	}
	return (ft_num_fdf2(buf, i, k, j));
}

int		ft_check_fdf(char *buf)
{
	int		i;
	int		j;
	int		k;
	int		res;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		if (buf[i] == ' ' && buf[i + 1] != ' ')
			j++;
		i++;
	}
	k = j;
	i = 0;
	if (buf[0] != '-' && (buf[0] < '0' || buf[0] > '9'))
		return (0);
	while (buf[i])
	{
		if (!(ft_num_fdf(buf, &i, &k, j)))
			return (0);
	}
	return (1);
}
