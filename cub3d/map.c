/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:41:58 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 18:20:22 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_mlx	*parse_resolution(char *line, t_mlx *data)
{
	int		i;
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

void			*cleanup(t_list *lst, t_map *map)
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

int				init_sprite(t_mlx *data)
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

static void		read_map2(t_mlx *data, char *line, t_list **lst)
{
	static int		size_ligne;
	t_list			*temp;

	if (data->t == 1)
	{
		size_ligne = ft_countwords(line, ' ');
		data->t++;
	}
	if (ft_countwords(line, ' ') != size_ligne)
		error("error :\nwrong map");
	temp = ft_lstnew(line, ft_strlen(line) + sizeof(char));
	ft_strdel(&line);
	ft_lstadd_front(lst, temp);
}

void			read_map(char *argv, t_mlx *data)
{
	int				i;
	char			*line;
	t_list			*lst;

	i = 0;
	data->t = 1;
	data->fd = open(argv, O_RDONLY);
	while (get_next_line(data->fd, &line) == 1)
	{
		if (line[0] == 'R')
			parse_resolution(line, data);
		else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
			|| line[0] == 'E' || line[0] == 'S')
			parse_texture(line, data);
		else if (line[0] == 'F')
			parse_couleur(line, data);
		else if (line[0] == 'C')
			parse_couleur(line, data);
		else if (line[0] == '1')
			read_map2(data, line, &lst);
	}
	ft_lstrev(&lst);
	new_map(ft_countwords((char *)lst->content, ' '), ft_lstcount(lst), data);
	remplir_map(data, lst);
	close(data->fd);
}
