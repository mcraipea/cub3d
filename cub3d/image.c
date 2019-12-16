/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:30:36 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/16 12:44:31 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image		*xpm_image(char *xpm, t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_xpm_file_to_image(mlx->mlx, xpm, &img->width,
			&img->height)) == NULL)
		return ((void*)del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
		&img->endian);
	img->bpp /= 8;
	img->width = img->stride / img->bpp;
	img->height = img->stride / img->bpp;
	return (img);
}

void		image_set_pixel(t_image *image, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= image->width || y >= image->height))
		*(int *)(image->ptr + ((x + y * image->width) * image->bpp)) = color;
}

void		clear_image(t_image *image)
{
	ft_bzero(image->ptr, image->width * image->height * image->bpp);
}

t_color		get_pixel(t_image *image, int x, int y)
{
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ((t_color)0x0);
	return ((t_color)*(int *)(image->ptr + ((x + y * image->width)
			* image->bpp)));
}

t_image		*del_image(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image		*new_image(t_mlx *mlx, int w, int h)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_new_image(mlx->mlx, w, h)) == NULL)
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
		&img->endian);
	img->bpp /= 8;
	img->width = w;
	img->height = h;
	return (img);
}
