/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:00:28 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 13:30:27 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color			get_pixel(t_image *image, int x, int y)
{
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ((t_color)0x0);
	return ((t_color)*(int *)(image->ptr + ((x + y * image->width)
			* image->bpp)));
}

static int		ft_lerpi(int first, int second)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first)));
}

t_color			clerp(t_color c1, t_color c2)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b);
	c.rgba.a = (char)0x00;
	return (c);
}

static int		ft_atoi_parse(char *line, int i)
{
	int		j;
	int		number;
	char	buffer[20];

	j = 0;
	ft_bzero(buffer, 20);
	while (line[i] >= '0' && line[i] <= '9')
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	number = ft_atoi(buffer);
	return (number);
}

t_mlx			*parse_couleur(char *line, t_mlx *data)
{
	int			i;

	i = 0;
	data->sol.rgba.a = 0;
	if (line[i] == 'F')
	{
		i++;
		while (line[i] == ' ')
			i++;
		data->sol.rgba.r = ft_atoi_parse(line, i);
		data->sol.rgba.g = ft_atoi_parse(line, i + 4);
		data->sol.rgba.b = ft_atoi_parse(line, i + 7);
	}
	else if (line[i++] == 'C')
	{
		while (line[i] == ' ')
			i++;
		data->plafond.rgba.r = ft_atoi_parse(line, i);
		data->plafond.rgba.g = ft_atoi_parse(line, i + 4);
		data->plafond.rgba.b = ft_atoi_parse(line, i + 7);
	}
	return (data);
}
