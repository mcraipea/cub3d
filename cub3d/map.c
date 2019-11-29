/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:41:58 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/29 15:07:21 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			parse_resolution(char *line)
{
	int 	i;
	int		j;
	int		number;
	t_map	map;

	i = 0;
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	number = 0;
	j = 1;
	while (line[i] >= 0 && line[i] <= 9)
	{
		number = number * j + line[i];
		j *= 10; 
	}
	map.width = number;
	while (line[i] == ' ')
		i++;
	number = 0;
	j = 1;
	while (line[i] >= 0 && line[i] <= 9)
	{
		number = number * j + line[i];
		j *= 10;
	}
	map.height = number;
	if (map.width == 0 || map.height == 0)
		return (0);
	return (1);
}

static int			parse_map(char *line, int i)
{
	int		j;
	t_map	map;

	j = 0;
	while (line[j] >= 0 && line[j] <= 2)
	{
		map.values[i][j] = line[j];
		j++;
	}
	if (map.size_line == 0)
		map.size_line = j;
	else
	{
			if (map.size_line != j)
				return (0);
	}
	return (1);
}

void				read_map(int fd)
{
	int		i;
//	int		fd;
	char	*line;

	i = 0;
	//fd = open("file", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			parse_resolution(line);
		else if (line[0] == 'N' && line[1] == 'O')
			parse_texture(line);
		else if (line[0] == 'S' && line[1] == 'O')
			parse_texture(line);
		else if (line[0] == 'W' && line[1] == 'E')
			parse_texture(line);
		else if (line[0] == 'E' && line[1] == 'A')
			parse_texture(line);
		else if (line[0] == 'S' && line[1] == ' ')
			parse_texture(line);
		else if (line[0] == 'F')
			parse_couleur(line);
		else if (line[0] == 'C')
			parse_couleur(line);
		else if (line[0] == 1)
		{
			parse_map(line, i);
			i++;
		}
	}
	close(fd);
}
