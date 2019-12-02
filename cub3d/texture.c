/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:48:40 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/02 16:08:44 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stddef.h>
/*
static void	free_textures(data_t *data)
{
	int i;

	i = 0;
	while (i < 20)
		del_image(data, data->tex[i++]);
}

int			load_textures(data_t *data)
{
	static char		*map[20] = { "brick.xpm", "wood.xpm", "metal.xpm", "stone.xpm", "grass.xpm", NULL };
	void			*img_ptr;
	int				i;
	char			*texture;

	i = 1;
	while (i < 20 && map[i - 1])
	{
		texture = ft_strjoin(("textures/", map[i - 1]);
		if ((img_ptr = xpm_image(texture, data)) == NULL)
		{
			ft_strdel(&texture);
			free_textures(data);
			return (1);
		}
		ft_strdel(&texture);
		data->tex[i] = img_ptr;
		i++;
	}
	mlx->max_tex = i - 1;
	mlx->tex[0] = NULL;
	mlx->floor = mlx->tex[2];
	mlx->ceiling = mlx->tex[4];
	return (0);
}
*/

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

data_t	parse_texture(char *line, data_t data)
{
	if (line[0] == 'N')
		data.texture.no = parse2_texture(line);
	else if (line[0] == 'S' && line[1] == 'O')
		data.texture.so = parse2_texture(line);
	else if (line[0] == 'W')
		data.texture.we = parse2_texture(line);
	else if (line[0] == 'E')
		data.texture.ea = parse2_texture(line);
	else if (line[0] == 'S' && line[1] == ' ')
		data.texture.s = parse2_texture(line);
	return (data);
}
