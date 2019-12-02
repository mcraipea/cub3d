/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:00:28 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/02 16:12:38 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

data_t			parse_couleur(char *line, data_t data)
{
	int			i;
	
	i = 0;
	data.color.rgba.a = 0;
	if (line[i++] == 'F')
	{
		while (line[i] == ' ')
			i++;
		data.color.rgba.r = ft_atoi_parse(line, i);
		while (line[i] >= '0' && line[i] <= '9' && line[i] != ',')
			i++;
		data.color.rgba.g = ft_atoi_parse(line, i + 1);
		while (line[i] >= '0' && line[i] <= '9' && line[i] != ',')
			i++;
		data.color.rgba.b = ft_atoi_parse(line, i + 1);
	}
	else if (line[i++] == 'C')
	{
		while (line[i] == ' ')
			i++;
		data.color.rgba.r = ft_atoi_parse(line, i);
		while (line[i] >= '0' && line[i] <= '9' && line[i] != ',')
			i++;
		data.color.rgba.g = ft_atoi_parse(line, i + 1);
		while (line[i] >= '0' && line[i] <= '9' && line[i] != ',')
			i++;
		data.color.rgba.b = ft_atoi_parse(line, i + 1);
	}
	return (data);
}
