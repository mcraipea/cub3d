/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:41:58 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/16 18:30:21 by mcraipea         ###   ########.fr       */
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
	if ((data->width_img = ft_atoi(buffer)) > 2560)
		data->width_img = 2560;
	while (line[i] == ' ')
		i++;
	ft_bzero(buffer, 20);
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	if ((data->height_img = ft_atoi(buffer)) > 1440)
		data->height_img = 1440;
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

static int			init_sprite(t_mlx *data)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	y = 0;
	if (!(data->tsprite = calloc(sizeof(t_sprite) * data->s_max, 1)))
		return (1);
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->values[y][x] == 2)
			{
				data->map->values[y][x] = 0;
				data->tsprite[i].x = x;
				data->tsprite[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

static t_mlx	*remplir_map(t_mlx *data, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = list;
	y = 0;
	data->s_max = 0;
	while (y < data->map->height)
	{
		x = 0;
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (NULL);
		while (x < data->map->width)
		{
			if (ft_strncmp(split[x], "N", 1) == 0 || ft_strncmp(split[x], "W", 1) == 0 || ft_strncmp(split[x], "E", 1) == 0 || ft_strncmp(split[x], "S", 1) == 0)
			{
				if (ft_strncmp(split[x], "N", 1) == 0)
					data->player.angle_start = 0;
				else if (ft_strncmp(split[x], "E", 1) == 0)
					data->player.angle_start = 90;
				else if (ft_strncmp(split[x], "S", 1) == 0)
					data->player.angle_start = 180;
				else if (ft_strncmp(split[x], "W", 1) == 0)
					data->player.angle_start = 270;
				data->player.x = (float)x;
				data->player.y = (float)y;
				ft_memset(split[x], 48, 1);
			}
			if ((data->map->values[y][x] = ft_atoi(split[x])) < 0 || data->map->values[y][x] > 2)
				return (NULL);
			if (data->map->values[y][x] == 2)
				data->s_max += 1;
			x++;
		}
		ft_splitdel(&split);
		lst = lst->next;
		y++;
	}
	if (init_sprite(data) == 1)
		return (NULL);
	cleanup(list, NULL);
	return (data);
}

void		read_map(char *argv, t_mlx *data)
{
	static int		size_ligne;
	int				t;
	int				i;
	int				fd;
	char			*line;
	t_list			*temp;
	t_list			*lst;

	i = 0;
	t = 1;
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
			if (t == 1)
			{
				size_ligne = ft_countwords(line, ' ');
				t++;
			}
			if (ft_countwords(line, ' ') != size_ligne)
				error("error : wrong map");
			temp = ft_lstnew(line, ft_strlen(line) + sizeof(char));
			ft_strdel(&line);
			ft_lstadd_front(&lst, temp);
		}
	}
	ft_lstrev(&lst);
	new_map(ft_countwords((char *)lst->content, ' '), ft_lstcount(lst), data);
	remplir_map(data, lst);
	close(fd);
}
