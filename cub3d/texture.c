/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:48:40 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/06 15:09:07 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < TEX_MAP_SIZE)
		del_image(mlx, mlx->tex[i++]);
}

int			load_textures(t_mlx *mlx)
{
	static char	*map[TEX_MAP_SIZE] = { "brick.xpm", "wood.xpm", "metal.xpm",
		"stone.xpm", "grass.xpm", NULL };
	t_image		*img;
	int			i;
	char		*t;

	i = 1;
	while (i < TEX_MAP_SIZE && map[i - 1])
	{
		t = ft_strjoin("textures/", map[i - 1]);
		if ((img = xpm_image(t, mlx)) == NULL)
		{
			ft_strdel(&t);
			free_textures(mlx);
			return (1);
		}
		ft_strdel(&t);
		mlx->tex[i] = img;
		i++;
	}
	mlx->max_tex = i - 1;
	mlx->tex[0] = NULL;
	mlx->floor = mlx->tex[2];
	mlx->ceiling = mlx->tex[4];
	return (0);
}

static char		*parse2_texture(char *line)
{
	int			i;
	int			j;
	char		buffer[400];
	char		*dest;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == 'O' || line[i] == 'N' ||
		line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == 'A')
		i++;
	while (line[i] != '\0')
		buffer[j++] = line[i++];
	buffer[j] = '\0';
	dest = ft_strdup(buffer);
	return (dest);
}

t_mlx	*parse_texture(char *line, t_mlx *data)
{
	if (line[0] == 'N')
		data->texture.no = parse2_texture(line);
	else if (line[0] == 'S' && line[1] == 'O')
		data->texture.so = parse2_texture(line);
	else if (line[0] == 'W')
		data->texture.we = parse2_texture(line);
	else if (line[0] == 'E')
		data->texture.ea = parse2_texture(line);
	else if (line[0] == 'S' && line[1] == ' ')
		data->texture.s = parse2_texture(line);
	return (data);
}
