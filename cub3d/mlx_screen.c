/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:22:05 by mcraipea          #+#    #+#             */
/*   Updated: 2019/12/18 13:32:50 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (!mlx)
		return (NULL);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

void		init(t_mlx *data)
{
	if ((data->mlx = mlx_init()) == NULL || (data->window = mlx_new_window
		(data->mlx, data->width_img, data->height_img, "cub3d")) == NULL ||
			(data->image = new_image(data, data->width_img, data->height_img))
				== NULL)
		error("error: mlx couldn't initialize properly");
}
