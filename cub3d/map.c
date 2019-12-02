/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:41:58 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/02 16:44:52 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static data_t		parse_resolution(char *line, data_t data)
{
	int 	i;
	int		j;
	char	buffer[20];

	i = 0;
	j = 0;
	ft_bzero(buffer, 20);
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	data.map.width = ft_atoi(buffer);
	while (line[i] == ' ')
		i++;
	ft_bzero(buffer, 20);
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	data.map.height = ft_atoi(buffer);
	return (data);
}

static data_t			parse_map(char *line, int i, data_t data)
{
	int		j;

	j = 0;
	while (line[j])
	{
		data.map.values[i][j] = line[j];
		j++;
	}
	if (data.map.size_line == 0)
		data.map.size_line = j;
	return (data);
}

data_t				read_map(int fd, data_t data)
{
	int		i;
//	int		fd;
	char	*line;

	i = 0;
	//fd = open("file", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			data = parse_resolution(line, data);
		else if (line[0] == 'N' && line[1] == 'O')
			data = parse_texture(line, data);
		else if (line[0] == 'S' && line[1] == 'O')
			data = parse_texture(line, data);
		else if (line[0] == 'W' && line[1] == 'E')
			data = parse_texture(line, data);
		else if (line[0] == 'E' && line[1] == 'A')
			data = parse_texture(line, data);
		else if (line[0] == 'S' && line[1] == ' ')
			data = parse_texture(line, data);
		else if (line[0] == 'F')
			data = parse_couleur(line, data);
		else if (line[0] == 'C')
			data = parse_couleur(line, data);
		else if (line[0] == 1)
		{
			data = parse_map(line, i, data);
			i++;
		}
	}
	close(fd);
	return (data);
}
