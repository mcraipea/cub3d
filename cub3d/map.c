/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:41:58 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/05 21:02:26 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_mlx		*parse_resolution(char *line, t_mlx *data)
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
	data->width_img = ft_atoi(buffer);
	while (line[i] == ' ')
		i++;
	ft_bzero(buffer, 20);
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	data->height_img = ft_atoi(buffer);
	return (data);
}

static void		*cleanup(t_list *lst, t_map *map)
{
	t_list	*next;
	int		i;

	i = 0;
	while (lst)
	{
		next = lst->next;
		ft_memdel(&lst->content);
		ft_memdel((void **)&lst);
		lst = next;
	}
	if (map)
	{
		if (map->values)
			while (i < map->height)
			{
				if (map->values + i)
					ft_memdel((void **)(map->values + i));
				i++;
			}
		ft_memdel((void **)&map);
	}
	return (NULL);
}

static t_list	*get_lines(int fd)
{
	static int	expected = -1;
	t_list		*lst;
	t_list		*temp;
	char		*line;
	int			ret;

	lst = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (expected == -1)
			expected = ft_countwords(line, ' ');
		if (expected == 0 || ft_countwords(line, ' ') != expected || (temp = ft_lstnew(line, (ft_strlen(line)) + sizeof(char))) == NULL)
			return (cleanup(lst, NULL));
		ft_strdel(&line);
		ft_lstadd_front(&lst, temp);
	}
	if (ret == -1)
		return (cleanup(lst, NULL));
	ft_lstrev(&lst);
	return (lst);
}

static t_mlx	*new_map(int w, int h, t_mlx *data)
{
	int		i;

	if (!(data->map = malloc(sizeof(t_map))))
		error("error\nmalloc doesn't works for map");
	data->map->width = w;
	data->map->height = h;
	if ((data->map->values = (int **)ft_calloc(sizeof(int *) * h, 1)) == NULL)
	{
		ft_memdel((void **)&data->map);
		return (NULL);
	}
	i = 0;
	while (i < h)
	{
		if ((data->map->values[i] = (int *)ft_calloc(sizeof(int) * w, 1)) == NULL)
		{
			while (i > 0)
				ft_memdel((void **)(data->map->values + --i));
			ft_memdel((void **)&data->map);
			return (NULL);
		}
		i++;
	}
	return (data);
}

static t_mlx	*remplir_map(t_mlx *data, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (NULL);
		while (x < data->map->width)
		{
			if ((data->map->values[y][x] = ft_atoi(split[x])) < 0 || data->map->values[y][x] > 2)
				return (NULL);
			x++;
		}
		ft_splitdel(&split);
		lst = lst->next;
		y++;
	}
	cleanup(list, NULL);
	return (data);
}

void		read_map(char *argv, t_mlx *data)
{
	int		i;
	int		fd;
	char	*line;
	t_list	*lst;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			parse_resolution(line, data);
		else if (line[0] == 'N' && line[1] == 'O')
			parse_texture(line, data);
		else if (line[0] == 'S' && line[1] == 'O')
			parse_texture(line, data);
		else if (line[0] == 'W' && line[1] == 'E')
			parse_texture(line, data);
		else if (line[0] == 'E' && line[1] == 'A')
			parse_texture(line, data);
		else if (line[0] == 'S' && line[1] == ' ')
			parse_texture(line, data);
		else if (line[0] == 'F')
			parse_couleur(line, data);
		else if (line[0] == 'C')
			parse_couleur(line, data);
		else if (line[0] == '1')
		{
			lst = get_lines(fd);
			new_map(ft_countwords((char *)lst->content, ' '), ft_lstcount(lst), data);
			remplir_map(data, lst);
		}
	}
	close(fd);
}
