/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:16:13 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 18:18:37 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx		*new_map(int w, int h, t_mlx *data)
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
		if ((data->map->values[i] =
			(int *)ft_calloc(sizeof(int) * w, 1)) == NULL)
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

static int	remplir_map2(t_mlx *data, char **split, int x, int y)
{
	if (ft_strncmp(split[x], "N", 1) == 0 || ft_strncmp(split[x],
		"W", 1) == 0 || ft_strncmp(split[x], "E", 1) == 0 ||
			ft_strncmp(split[x], "S", 1) == 0)
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
	if ((data->map->values[y][x] = ft_atoi(split[x])) < 0 ||
		data->map->values[y][x] > 2)
		return (0);
	if (data->map->values[y][x] == 2)
		data->s_max += 1;
	return (1);
}

t_mlx		*remplir_map(t_mlx *data, t_list *list)
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
		while (++x < data->map->width)
			remplir_map2(data, split, x, y);
		ft_splitdel(&split);
		lst = lst->next;
		y++;
	}
	if (init_sprite(data) == 1)
		return (NULL);
	cleanup(list, NULL);
	return (data);
}
