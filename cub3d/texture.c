/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:48:40 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 16:26:35 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		free_textures(t_mlx *mlx)
{
	del_image(mlx, mlx->tex_no);
	del_image(mlx, mlx->tex_so);
	del_image(mlx, mlx->tex_we);
	del_image(mlx, mlx->tex_ea);
	del_image(mlx, mlx->tex_s);
	return (1);
}

int				load_textures(t_mlx *mlx)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((mlx->tex_no = xpm_image(mlx->texture.no, mlx)) == NULL)
		j = free_textures(mlx);
	i++;
	if ((mlx->tex_so = xpm_image(mlx->texture.so, mlx)) == NULL)
		j = free_textures(mlx);
	i++;
	if ((mlx->tex_we = xpm_image(mlx->texture.we, mlx)) == NULL)
		j = free_textures(mlx);
	i++;
	if ((mlx->tex_ea = xpm_image(mlx->texture.ea, mlx)) == NULL)
		j = free_textures(mlx);
	i++;
	if ((mlx->tex_s = xpm_image(mlx->texture.s, mlx)) == NULL)
		j = free_textures(mlx);
	i++;
	return (j);
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

t_mlx			*parse_texture(char *line, t_mlx *data)
{
	if (line[0] == 'N' && line[1] == 'O')
		data->texture.no = parse2_texture(line);
	else if (line[0] == 'S' && line[1] == 'O')
		data->texture.so = parse2_texture(line);
	else if (line[0] == 'W' && line[1] == 'E')
		data->texture.we = parse2_texture(line);
	else if (line[0] == 'E' && line[1] == 'A')
		data->texture.ea = parse2_texture(line);
	else if (line[0] == 'S' && line[1] == ' ')
		data->texture.s = parse2_texture(line);
	return (data);
}
