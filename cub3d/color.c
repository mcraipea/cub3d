/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:00:28 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/29 12:47:28 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	number(char *line, int i)
{
	int		number;
	int		j;

	number = 0;
	j = 1;
	while (line[i] >= 0 && line[i] <= 9)
	{
		number = number * j + line[i];
		j *= 10;
	}
	return (number);
}

void		parse_couleur(char *line)
{
	int			i;
	t_color		color;
	
	i = 0;
	color.rgba.a = 0;
	if (line[i++] == 'F')
	{
		while (line[i] == ' ')
			i++;
		color.rgba.r = number(line, i);
		while (line[i] >= 0 && line[i] <= 9 && line[i] != ',')
			i++;
		color.rgba.g = number(line, i + 1);
		while (line[i] >= 0 && line[i] <= 9 && line[i] != ',')
			i++;
		color.rgba.b = number(line, i + 1);
	}
	else if (line[i++] == 'C')
	{
		while (line[i] == ' ')
			i++;
		color.rgba.r = number(line, i);
		while (line[i] >= 0 && line[i] <= 9 && line[i] != ',')
			i++;
		color.rgba.g = number(line, i + 1);
		while (line[i] >= 0 && line[i] <= 9 && line[i] != ',')
			i++;
		color.rgba.b = number(line, i + 1);
	}
}
